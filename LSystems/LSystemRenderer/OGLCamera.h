#ifndef OGLCAMERA_H
#define OGLCAMERA_H

#include "..\..\include\glm\glm.hpp"

namespace lrend
{

	enum MovementDirection
	{
		FORWARD, BACKWARDS, LEFT, RIGHT
	};

	class OGLCamera
	{
	private:
		glm::vec3 position, front, right;
		glm::vec3 up, worldUp;

		float pitch, yaw;
		float speed, sensitivity, fov;

		void updateCameraVectors();

	public:
		OGLCamera(glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
			float yw = -90.0f, float pch = 0.0f);
		OGLCamera(const OGLCamera&) = delete;
		OGLCamera& operator=(const OGLCamera&) = delete;
		~OGLCamera() = default;

		const glm::vec3& getPosition() const;
		float getFOV() const;
		glm::mat4 getViewMatrix() const;
		void move(MovementDirection direction, float deltaTime);
		void look(float xOffset, float yOffset);
		void zoom(float yOffset);
	};

}

#endif
