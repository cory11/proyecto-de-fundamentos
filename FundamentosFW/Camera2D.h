#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

class Camera2D
{
private:
	glm::vec2 _position;
	float _scale;
	bool _needsMatrixUpdate;
	glm::mat4 _cameraMatrix;
	glm::mat4 _orthoMatrix;
	int _screenWidth;
	int _screenHeight;

public:
	Camera2D();
	~Camera2D();

	void update();
	void init(
		int screenWidth, int screenHeight);

	void setPosition(
		const glm::vec2& newPosition) {
		_position = newPosition;
		_needsMatrixUpdate = true;
	}

	void setScale(float newScale) {
		_scale = newScale;
		_needsMatrixUpdate = true;
	}

	glm::mat4 getCameraMatrix() {
		return _cameraMatrix;
	}

	glm::vec2 getPosition() {
		return _position;
	}
	float getScale() { return _scale; }
};

