#pragma once

//
// Flounder header file
//

#ifdef FLOUNDER_PLATFORM_WINDOWS
#include <Windows.h>
#endif

#include "camera/camera.hpp"
#include "camera/icamera.hpp"
#include "camera/iplayer.hpp"
#include "deferred/rendererdeferred.hpp"
#include "devices/audio.hpp"
#include "devices/display.hpp"
#include "devices/joysticks.hpp"
#include "devices/keyboard.hpp"
#include "devices/mouse.hpp"
#include "entities/components/componentalpha.hpp"
#include "entities/entity.hpp"
#include "entities/entityrender.hpp"
#include "entities/icomponent.hpp"
#include "events/eventchange.hpp"
#include "events/events.hpp"
#include "events/eventstandard.hpp"
#include "events/eventtime.hpp"
#include "events/ievent.hpp"
#include "fbos/depthbuffer.hpp"
#include "fbos/Fbo.hpp"
#include "flounder.hpp"
#include "fonts/character.hpp"
#include "fonts/line.hpp"
#include "fonts/metafile.hpp"
#include "fonts/rendererfonts.hpp"
#include "fonts/text.hpp"
#include "fonts/fonttype.hpp"
#include "fonts/word.hpp"
#include "engine/Engine.hpp"
#include "platforms/glfw/GlfwUpdater.hpp"
#include "engine/IModule.hpp"
#include "engine/iupdater.hpp"
#include "inputs/axisbutton.hpp"
#include "maths/Transform.hpp"
#include "models/material.hpp"
#include "noise/noisefast.hpp"
#include "particles/particle.hpp"
#include "particles/particles.hpp"
#include "particles/particlesystem.hpp"
#include "particles/particletype.hpp"
#include "particles/rendererparticles.hpp"
#include "particles/spawns/ispawnparticle.hpp"
#include "particles/spawns/spawncircle.hpp"
#include "particles/spawns/spawnline.hpp"
#include "particles/spawns/spawnpoint.hpp"
#include "particles/spawns/spawnsphere.hpp"
#include "post/filters/filterdefault.hpp"
#include "shadows/renderershadows.hpp"
#include "shadows/shadowbox.hpp"
#include "shadows/shadows.hpp"
#include "skyboxes/rendererskyboxes.hpp"
#include "skyboxes/skybox.hpp"
#include "skyboxes/skyboxes.hpp"
#include "sounds/sound.hpp"
#include "stb/stb_image.h"
#include "renderer/swapchain/swapchain.hpp"
#include "terrains/biome.hpp"
#include "terrains/rendererterrains.hpp"
#include "terrains/terrain.hpp"
#include "terrains/terrains.hpp"
#include "test/renderertest.hpp"
#include "uis/inputslider.hpp"
#include "uis/inputgrabber.hpp"
#include "uis/inputtext.hpp"
#include "uis/inputbutton.hpp"
#include "uis/inputdelay.hpp"
#include "uis/uialign.hpp"
#include "guis/gui.hpp"
#include "uis/uis.hpp"
#include "uis/uiselector.hpp"
#include "uis/imanageruis.hpp"
#include "uis/overlaystartup.hpp"
#include "guis/rendererguis.hpp"
#include "uis/uiobject.hpp"
#include "uis/containerscreen.hpp"
#include "helpers/helperarray.hpp"
#include "helpers/helperfile.hpp"
#include "helpers/helperstring.hpp"
#include "inputs/axiscompound.hpp"
#include "inputs/axisjoystick.hpp"
#include "inputs/buttoncompound.hpp"
#include "inputs/buttonjoystick.hpp"
#include "inputs/buttonkeyboard.hpp"
#include "inputs/buttonmouse.hpp"
#include "inputs/iaxis.hpp"
#include "inputs/ibutton.hpp"
#include "lights/attenuation.hpp"
#include "lights/fog.hpp"
#include "lights/light.hpp"
#include "maths/colour.hpp"
#include "maths/delta.hpp"
#include "maths/maths.hpp"
#include "maths/matrix2x2.hpp"
#include "maths/matrix3x3.hpp"
#include "maths/matrix4x4.hpp"
#include "maths/quaternion.hpp"
#include "maths/timer.hpp"
#include "maths/vector2.hpp"
#include "maths/vector3.hpp"
#include "maths/vector4.hpp"
#include "models/model.hpp"
#include "models/vertexdata.hpp"
#include "physics/aabb.hpp"
#include "physics/frustum.hpp"
#include "physics/icollider.hpp"
#include "physics/intersect.hpp"
#include "physics/ray.hpp"
#include "physics/sphere.hpp"
#include "post/filters/filterbloom1.hpp"
#include "post/filters/filterbloom2.hpp"
#include "post/filters/filterblurhorizontal.hpp"
#include "post/filters/filterblurvertical.hpp"
#include "post/filters/filtercombine.hpp"
#include "post/filters/filtercrt.hpp"
#include "post/filters/filterdarken.hpp"
#include "post/filters/filteremboss.hpp"
#include "post/filters/filterfxaa.hpp"
#include "post/filters/filtergrain.hpp"
#include "post/filters/filtergrey.hpp"
#include "post/filters/filterlensflare.hpp"
#include "post/filters/filtermotion.hpp"
#include "post/filters/filternegative.hpp"
#include "post/filters/filterpixel.hpp"
#include "post/filters/filtersepia.hpp"
#include "post/filters/filtertiltshift.hpp"
#include "post/filters/filtertone.hpp"
#include "post/filters/filterwobble.hpp"
#include "post/ipostfilter.hpp"
#include "post/ipostpipeline.hpp"
#include "post/pipelines/pipelinebloom.hpp"
#include "post/pipelines/pipelinegaussian.hpp"
#include "post/pipelines/pipelinepaused.hpp"
#include "processing/iprocessor.hpp"
#include "processing/irequest.hpp"
#include "processing/graphic/processorgraphic.hpp"
#include "processing/graphic/requestgraphic.hpp"
#include "processing/processing.hpp"
#include "processing/queue.hpp"
#include "processing/resource/processorresource.hpp"
#include "processing/resource/requestresource.hpp"
#include "renderer/irenderer.hpp"
#include "renderer/imanagerrender.hpp"
#include "renderer/renderer.hpp"
#include "shaders/shader.hpp"
#include "shaders/shadertype.hpp"
#include "space/ispatialobject.hpp"
#include "space/ispatialstructure.hpp"
#include "space/structurebasic.hpp"
#include "standards/istandard.hpp"
#include "standards/standards.hpp"
#include "tasks/tasks.hpp"
#include "textures/texture.hpp"
#include "visual/driverbounce.hpp"
#include "visual/driverconstant.hpp"
#include "visual/driverfade.hpp"
#include "visual/driverlinear.hpp"
#include "visual/driversinwave.hpp"
#include "visual/driverslide.hpp"
#include "visual/idriver.hpp"
#include "visual/interpolation/smoothfloat.hpp"
#include "waters/rendererwaters.hpp"
#include "waters/water.hpp"
#include "waters/waters.hpp"
#include "worlds/worlds.hpp"