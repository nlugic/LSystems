#ifndef OGLCAMERA_H
#define OGLCAMERA_H

#include "..\..\include\glm\glm.hpp"

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
		OGLCamera(const OGLCameraConfig& config = default_ogl_camera_config);
		OGLCamera(const OGLCamera&) = delete;
		OGLCamera(OGLCamera&&) = delete;
		OGLCamera& operator=(const OGLCamera&) = delete;
		~OGLCamera() = default;

		const glm::vec3& getPosition() const;
		float getFOV() const;
		glm::mat4 getViewMatrix() const;
		void move(MovementDirection direction, float delta_time);
		void look(float x_offset, float y_offset);
		void zoom(float y_offset);
	};

}

#endif
