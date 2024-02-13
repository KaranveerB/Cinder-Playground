#include "cinder/Rand.h"
#include "cinder/Vector.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;

using glm::vec2;

const float c_maxRad = 5.0f;
const float c_minRad = 1.0f;

class Particle {
 private:
	vec2 m_loc;
	vec2 m_dir = Rand::randVec2();
	float m_vel = Rand::randFloat(5.0f);
	float m_rad;

 public:
	explicit Particle(const vec2 &loc) : m_loc(loc), m_rad(Rand::randFloat(c_minRad, c_maxRad)) {}

	void update() {
		m_loc += m_dir * m_vel;
	}

	void draw() const {
		gl::drawSolidCircle(m_loc, m_rad, 20);
	}
};

class ParticleController {
 private:
	std::vector<Particle> m_particles;

 public:
	void setup(int resX, int resY) {
		int xMax = resX / 2 / c_maxRad;
		int yMax = resY / 2 / c_maxRad;
		for (int xi = 0; xi < xMax; xi++) {
			for (int yi = 0; yi < yMax; yi++) {
				float x = (static_cast<float>(xi) * 2.5) * c_maxRad;
				float y = (static_cast<float>(yi) * 2.5) * c_maxRad;

				m_particles.emplace_back(vec2(x, y));
			}
		}
	}

	void draw() {
		for (const Particle &particle : m_particles) {
			particle.draw();
		}
	}
};

class P5Play : public App {
 private:
	ParticleController pc;
 public:
	void setup() override;
	void draw() override;
};

void P5Play::setup() {
	setWindowSize(800, 600);
	pc.setup(800, 600);
}

void P5Play::draw() {
	pc.draw();
}

CINDER_APP(P5Play, RendererGl)
