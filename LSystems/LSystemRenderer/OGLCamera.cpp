
#include "OGLCamera.h"
#include "..\..\include\glm\gtc\matrix_transform.hpp"

namespace lrend
{

	OGLCamera::OGLCamera(const OGLCameraConfig& config)
		:position(config.position), world_up(config.world_up), pitch(config.pitch), yaw(config.yaw),
		fov(config.fov), speed(config.speed), sensitivity(config.sensitivity) { updateCameraVectors(); }

	const glm::vec3& OGLCamera::getPosition() const { return position; }

	float OGLCamera::getFOV() const { return fov; }

	glm::mat4 OGLCamera::getViewMatrix() const { return glm::lookAt(position, position + front, up); }

	void OGLCamera::move(MovementDirection direction, float delta_time)
	{
		float velocity = speed * delta_time;

		switch (direction)
		{
			case FORWARD: position += front * velocity; break;
			case BACKWARDS: position -= front * velocity; break;
			case LEFT: position -= right * velocity; break;
			case RIGHT: position += right * velocity; break;
		}
	}

	void OGLCamera::look(float x_offset, float y_offset)
	{
		yaw += x_offset * sensitivity;
		pitch += y_offset * sensitivity;

		pitch = glm::clamp(pitch, -89.9f, 89.9f);

		updateCameraVectors();
	}

	void OGLCamera::zoom(float y_offset) { fov = glm::clamp(fov -= y_offset, 1.0f, 45.0f); }

	void OGLCamera::updateCameraVectors()
	{
		glm::vec3 new_front;
		new_front.x = std::cos(glm::radians(yaw)) * std::cos(glm::radians(pitch));
		new_front.y = std::sin(glm::radians(pitch));
		new_front.z = std::sin(glm::radians(yaw)) * std::cos(glm::radians(pitch));
		front = glm::normalize(new_front);

		right = glm::normalize(glm::cross(front, world_up));
		up = glm::normalize(glm::cross(right, front));
	}

}
