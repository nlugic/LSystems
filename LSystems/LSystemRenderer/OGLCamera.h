#ifndef OGLCAMERA_H
#define OGLCAMERA_H

#include "..\..\include\glm\glm.hpp"
#include "..\..\include\glm\gtc\matrix_transform.hpp"

namespace lrend
{

	enum MovementDirection { FORWARD, BACKWARDS, LEFT, RIGHT };

	struct OGLCameraConfig
	{
		glm::vec3 position, world_up;
		float pitch, yaw, fov, speed, sensitivity;
	};

	const OGLCameraConfig default_ogl_camera_config =
	{
		glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f),
		0.0f, -90.0f, 45.0f, 5.0f, 0.1f
	};

	class OGLCamera
	{
	private:
		glm::vec3 position, front, right, up, world_up;
		float pitch, yaw, fov, speed, sensitivity;

		void updateCameraVectors();

	public:
		inline OGLCamera(const OGLCameraConfig& config = default_ogl_camera_config)
			:position(config.position), world_up(config.world_up), pitch(config.pitch), yaw(config.yaw),
			fov(config.fov), speed(config.speed), sensitivity(config.sensitivity) { updateCameraVectors(); }
		OGLCamera(const OGLCamera&) = delete;
		OGLCamera(OGLCamera&&) = delete;
		OGLCamera& operator=(const OGLCamera&) = delete;
		inline ~OGLCamera() = default;

		inline const glm::vec3& getPosition() const { return position; }
		inline float getFOV() const { return fov; }
		inline glm::mat4 getViewMatrix() const { return glm::lookAt(position, position + front, up); }
		void move(MovementDirection direction, float delta_time);
		void look(float x_offset, float y_offset);
		inline void zoom(float y_offset) { fov = glm::clamp(fov -= y_offset, 1.0f, 45.0f); }
	};

}

#endif
