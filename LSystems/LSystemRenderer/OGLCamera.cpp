
#include "OGLCamera.h"

#include "..\..\include\glm\gtc\matrix_transform.hpp"

namespace lrend
{

	OGLCamera::OGLCamera(glm::vec3 pos, glm::vec3 up, float y, float p)
		:front(glm::vec3(0.0f, 0.0f, -1.0f)), speed(2.0f), sensitivity(0.1f),
		fov(45.0f), position(pos), worldUp(up), yaw(y), pitch(p)
	{
		updateCameraVectors();
	}

	OGLCamera::OGLCamera(float posX, float posY, float posZ, float upX, float upY, float upZ, float y, float p)
		:front(glm::vec3(0.0f, 0.0f, -1.0f)), speed(2.0f), sensitivity(0.1f), fov(45.0f),
		position(glm::vec3(posX, posY, posZ)), worldUp(glm::vec3(upX, upY, upZ)), yaw(y), pitch(p)
	{
		updateCameraVectors();
	}

	glm::mat4 OGLCamera::getViewMatrix()
	{
		return glm::lookAt(position, position + front, up);
	}

	void OGLCamera::move(MovementDirection direction, float deltaTime)
	{
		float velocity = speed * deltaTime;

		switch (direction)
		{
			case FORWARD: position += front * velocity;
				break;
			case BACKWARDS: position -= front * velocity;
				break;
			case LEFT: position -= right * velocity;
				break;
			case RIGHT: position += right * velocity;
				break;
		}
	}

	void OGLCamera::look(float xOffset, float yOffset, bool constrainPitch)
	{
		xOffset *= sensitivity;
		yOffset *= sensitivity;

		yaw += xOffset;
		pitch += yOffset;

		if (constrainPitch)
		{
			if (pitch >= 89.0f)
				pitch = 89.0f;
			if (pitch <= -89.0f)
				pitch = -89.0f;
		}

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
		glm::vec3 fr;
		fr.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		fr.y = sin(glm::radians(pitch));
		fr.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		front = glm::normalize(fr);

		right = glm::normalize(glm::cross(front, worldUp));
		up = glm::normalize(glm::cross(right, front));
	}

}
