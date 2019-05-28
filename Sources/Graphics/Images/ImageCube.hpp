﻿#pragma once

#include "Helpers/NonCopyable.hpp"
#include "Resources/Resource.hpp"
#include "Image.hpp"

namespace acid
{
/**
 * @brief Resource that represents a cubemap image.
 */
class ImageCube :
	public NonCopyable,
	public Descriptor,
	public Resource
{
public:
	/**
	 * Creates a new cubemap image, or finds one with the same values.
	 * @param metadata The metadata to decode values from.
	 * @return The cubemap image with the requested values.
	 */
	static std::shared_ptr<ImageCube> Create(const Metadata &metadata);

	/**
	 * Creates a new cubemap image.
	 * @param filename The file to load the image from.
	 * @param fileSuffix The files extension type (ex .png).
	 * @param filter The magnification/minification filter to apply to lookups.
	 * @param addressMode The addressing mode for outside [0..1] range.
	 * @param anisotropic If anisotropic filtering is enabled.
	 * @param mipmap If mapmaps will be generated.
	 * @return The cubemap image with the requested values.
	 */
	static std::shared_ptr<ImageCube> Create(const std::string &filename, const std::string &fileSuffix, const VkFilter &filter = VK_FILTER_LINEAR,
		const VkSamplerAddressMode &addressMode = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE, const bool &anisotropic = true, const bool &mipmap = true);

	/**
	 * Creates a new cubemap image.
	 * @param filename The file to load the image from.
	 * @param fileSuffix The files extension type (ex .png).
	 * @param filter The magnification/minification filter to apply to lookups.
	 * @param addressMode The addressing mode for outside [0..1] range.
	 * @param anisotropic If anisotropic filtering is enabled.
	 * @param mipmap If mapmaps will be generated.
	 * @param load If this resource will be loaded immediately, otherwise {@link ImageCube#Load} can be called later.
	 */
	explicit ImageCube(std::string filename, std::string fileSuffix = ".png", const VkFilter &filter = VK_FILTER_LINEAR,
		const VkSamplerAddressMode &addressMode = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE, const bool &anisotropic = true, const bool &mipmap = true, const bool &load = true);

	/**
	 * Creates a new cubemap image.
	 * @param extent The images extent in pixels.
	 * @param pixels The initial pixels to use in the Image. {@link ImageCube#GetPixels} to get a copy of the pixels, and {@link ImageCube#SetPixels} to set the pixels.
	 * @param format The format and type of the texel blocks that will be contained in the image.
	 * @param layout The layout that the image subresources accessible from.
	 * @param usage The intended usage of the image.
	 * @param filter The magnification/minification filter to apply to lookups.
	 * @param addressMode The addressing mode for outside [0..1] range.
	 * @param samples The number of samples per texel.
	 * @param anisotropic If anisotropic filtering is enabled.
	 * @param mipmap If mapmaps will be generated.
	 */
	ImageCube(const Vector2ui &extent, std::unique_ptr<uint8_t[]> pixels = nullptr, const VkFormat &format = VK_FORMAT_R8G8B8A8_UNORM,
		const VkImageLayout &layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL, const VkImageUsageFlags &usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_STORAGE_BIT,
		const VkFilter &filter = VK_FILTER_LINEAR, const VkSamplerAddressMode &addressMode = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE,
		const VkSampleCountFlagBits &samples = VK_SAMPLE_COUNT_1_BIT, const bool &anisotropic = false, const bool &mipmap = false);

	~ImageCube();

	static VkDescriptorSetLayoutBinding GetDescriptorSetLayout(const uint32_t &binding, const VkDescriptorType &descriptorType, const VkShaderStageFlags &stage,
		const uint32_t &count);

	WriteDescriptorSet GetWriteDescriptor(const uint32_t &binding, const VkDescriptorType &descriptorType, const std::optional<OffsetSize> &offsetSize) const override;

	void Load() override;

	/**
	 * Copies the images pixels from memory.
	 * @param extent The sampled images extent.
	 * @param mipLevel The mipmap level index to sample.
	 * @param arrayLayer The array layer to sample.
	 * @return A copy of the images pixels.
	 */
	std::unique_ptr<uint8_t[]> GetPixels(Vector2ui &extent, const uint32_t &mipLevel, const uint32_t &arrayLayer) const;

	/**
	 * Copies the images pixels from memory.
	 * @param extent The sampled images extent (height will be scaled by the amount of layers).
	 * @param mipLevel The mipmap level index to sample.
	 * @return A copy of the images pixels.
	 */
	std::unique_ptr<uint8_t[]> GetPixels(Vector2ui &extent, const uint32_t &mipLevel = 0) const;

	/**
	 * Sets the pixels of this image.
	 * @param pixels The pixels to copy from.
	 * @param layerCount The amount of layers contained in the pixels.
	 * @param baseArrayLayer The first layer to copy into.
	 */
	void SetPixels(const uint8_t *pixels, const uint32_t &layerCount, const uint32_t &baseArrayLayer);

	static std::unique_ptr<uint8_t[]> LoadPixels(const std::string &filename, const std::string &fileSuffix, const std::vector<std::string> &fileSides, Vector2ui &extent,
		uint32_t &components, VkFormat &format);

	const std::string &GetFilename() const { return m_filename; };

	const std::string &GetFileSuffix() { return m_fileSuffix; };

	const std::vector<std::string> &GetFileSides() { return m_fileSides; };

	const VkFilter &GetFilter() const { return m_filter; }

	const VkSamplerAddressMode &GetAddressMode() const { return m_addressMode; }

	const bool &IsAnisotropic() const { return m_anisotropic; }

	const bool &IsMipmap() const { return m_mipmap; }

	const VkSampleCountFlagBits &GetSamples() const { return m_samples; }

	const VkImageLayout &GetLayout() const { return m_layout; }

	const VkImageUsageFlags &GetUsage() const { return m_usage; }

	const uint32_t &GetComponents() const { return m_components; }

	const Vector2ui &GetExtent() const { return m_extent; }

	const uint32_t &GetMipLevels() const { return m_mipLevels; }

	const VkImage &GetImage() const { return m_image; }

	const VkDeviceMemory &GetMemory() { return m_memory; }

	const VkSampler &GetSampler() const { return m_sampler; }

	const VkImageView &GetView() const { return m_view; }

	const VkFormat &GetFormat() const { return m_format; }

	friend const Metadata &operator>>(const Metadata &metadata, ImageCube &image);

	friend Metadata &operator<<(Metadata &metadata, const ImageCube &image);

private:
	std::string m_filename;
	std::string m_fileSuffix;
	std::vector<std::string> m_fileSides;

	VkFilter m_filter;
	VkSamplerAddressMode m_addressMode;
	bool m_anisotropic;
	bool m_mipmap;
	VkSampleCountFlagBits m_samples;
	VkImageLayout m_layout;
	VkImageUsageFlags m_usage;

	uint32_t m_components;
	Vector2ui m_extent;
	std::unique_ptr<uint8_t[]> m_loadPixels;
	uint32_t m_mipLevels;

	VkImage m_image;
	VkDeviceMemory m_memory;
	VkSampler m_sampler;
	VkImageView m_view;
	VkFormat m_format;
};
}
