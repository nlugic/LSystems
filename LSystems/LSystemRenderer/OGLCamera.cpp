
#include "OGLCamera.h"
#include "..\..\include\glm\gtc\matrix_transform.hpp"

namespace lrend
{

	OGLCamera::OGLCamera(const OGLCameraConfig& config)
		:position(config.position), worldUp(config.worldUp), pitch(config.pitch), yaw(config.yaw),
		fov(config.fov), speed(config.speed), sensitivity(config.sensitivity)
	{
		updateCameraVectors();
	}

	const glm::vec3& OGLCamera::getPosition() const
	{
		return position;
	}

	float OGLCamera::getFOV() const
	{
		return fov;
	}

	glm::mat4 OGLCamera::getViewMatrix() const
	{
		return glm::lookAt(position, position + front, up);
	}

	void OGLCamera::move(MovementDirection direction, float deltaTime)
	{
		float velocity = speed * deltaTime;

		switch (direction)
		{
			case FORWARD: position += front * velocity; break;
			case BACKWARDS: position -= front * velocity; break;
			case LEFT: position -= right * velocity; break;
			case RIGHT: position += right * velocity; break;
		}
	}

	void OGLCamera::look(float xOffset, float yOffset)
	{
		yaw += xOffset * sensitivity;
		pitch += yOffset * sensitivity;

		pitch = glm::clamp(pitch, -89.9f, 89.9f);

		updateCameraVectors();
	}

	void OGLCamera::zoom(float yOffset)
	{
		if (fov >= 1.0f && fov <= 45.0f)
			fov -= yOffset;

		fov = glm::clamp(fov, 1.0f, 45.0f);
	}

	void OGLCamera::updateCameraVectors()
	{
		glm::vec3 newFront;
		newFront.x = std::cos(glm::radians(yaw)) * std::cos(glm::radians(pitch));
		newFront.y = std::sin(glm::radians(pitch));
		newFront.z = std::sin(glm::radians(yaw)) * std::cos(glm::radians(pitch));
		front = glm::normalize(newFront);

		right = glm::normalize(glm::cross(front, worldUp));
		up = glm::normalize(glm::cross(right, front));
	}

}
