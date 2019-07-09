#ifndef OGLCAMERA_H
#define OGLCAMERA_H

#include "..\..\include\glm\glm.hpp"

namespace lrend
{

	enum MovementDirection
	{
		FORWARD, BACKWARDS, LEFT, RIGHT
	};

	struct OGLCameraConfig
	{
		glm::vec3 position, worldUp;
		float pitch, yaw, fov, speed, sensitivity;
	};

	const OGLCameraConfig defaultOGLCameraConfig =
	{
		glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f),
		0.0f, -90.0f, 45.0f, 5.0f, 0.1f
	};

	class OGLCamera
	{
	private:
		glm::vec3 position, front, right;
		glm::vec3 up, worldUp;

		float pitch, yaw;
		float fov, speed, sensitivity;

		void updateCameraVectors();

	public:
		OGLCamera(const OGLCameraConfig& config = defaultOGLCameraConfig);
		OGLCamera(const OGLCamera&) = delete;
		OGLCamera& operator=(const OGLCamera&) = delete;

		const glm::vec3& getPosition() const;
		float getFOV() const;
		glm::mat4 getViewMatrix() const;
		void move(MovementDirection direction, float deltaTime);
		void look(float xOffset, float yOffset);
		void zoom(float yOffset);
	};

}

#endif
