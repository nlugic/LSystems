
#include "OGLCamera.h"
#include "..\..\include\glm\gtc\matrix_transform.hpp"

namespace lrend
{

	OGLCamera::OGLCamera(glm::vec3 pos)
		:front(glm::vec3(0.0f, 0.0f, -1.0f)), speed(2.0f), sensitivity(0.1f),
		fov(45.0f), position(pos), worldUp(glm::vec3(0.0f, 1.0f, 0.0f)), yaw(-90.0f), pitch(0.0f)
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

		if (direction == FORWARD)
			position += front * velocity;
		if (direction == BACKWARDS)
			position -= front * velocity;
		if (direction == LEFT)
			position -= right * velocity;
		if (direction == RIGHT)
			position += right * velocity;
	}

	void OGLCamera::look(float xOffset, float yOffset)
	{
		yaw += xOffset * sensitivity;
		pitch += yOffset * sensitivity;

		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;

		updateCameraVectors();
	}

	void OGLCamera::zoom(float yOffset)
	{
		if (fov >= 1.0f && fov <= 45.0f)
			fov -= yOffset;
		if (fov <= 1.0f)
			fov = 1.0f;
		if (fov >= 45.0f)
			fov = 45.0f;
	}

	void OGLCamera::updateCameraVectors()
	{
		glm::vec3 newFront;
		newFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		newFront.y = sin(glm::radians(pitch));
		newFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		front = glm::normalize(newFront);

		right = glm::normalize(glm::cross(front, worldUp));
		up = glm::normalize(glm::cross(right, front));
	}

}
