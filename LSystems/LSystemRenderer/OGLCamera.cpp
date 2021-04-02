
#include "OGLCamera.h"

namespace lrend
{

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
