#define numOfParticles 50
#define G 1

class particle {
	public:
		Vector pos;
		Vector vel;
		float mass;
		particle() {
			pos.x = random(0, width);
			pos.y = random(0, height);
			vel.x = 0;
			vel.y = 0;
			mass = random(1, 5);
		}
		void show() {
			fill(255, 0, 0, 255);
			circle(pos.x, pos.y, mass);
		}
		void move() {
			pos.x += vel.x;
			pos.y += vel.y;
		}
};

static vector <particle> particles;

void coll() {
	for (int a = 0; a < particles.size(); a++) {
		for (int b = 0; b < particles.size(); b++) {
			if (a != b) {
				float d = dist(particles[a].pos.x, particles[a].pos.y, particles[b].pos.x, particles[b].pos.y);
				if (d < particles[a].mass + particles[b].mass) {
					if (particles[a].mass > particles[b].mass) {
						particles[a].mass += particles[b].mass;
						particles.erase(particles.begin() + b);
					}
				}
			}
		}
	}
}

void gravitate() {
	for (int a = 0; a < particles.size(); a++) {
		for (int b = 0; b < particles.size(); b++) {
			if (a != b) {
				float v = 0;
				float distance = dist(particles[a].pos.x, particles[a].pos.y, particles[b].pos.x, particles[b].pos.y);
				float distanceSquared = pow(distance, 2);
				float angle = atan2(particles[b].pos.y - particles[a].pos.y, particles[b].pos.x - particles[a].pos.x);
				v = G * particles[b].mass / (distanceSquared);
				particles[a].vel.x += cos(angle) * v;
				particles[a].vel.y += sin(angle) * v;
			}
		}
	}
}

void loopGame() {
	for (int a = 0; a < particles.size(); a++) {
		if (particles[a].pos.x < -particles[a].mass) particles[a].pos.x = width + particles[a].mass;
		if (particles[a].pos.x > width + particles[a].mass) particles[a].pos.x = -particles[a].mass;
		if (particles[a].pos.y < -particles[a].mass) particles[a].pos.y = height + particles[a].mass;
		if (particles[a].pos.y > height + particles[a].mass) particles[a].pos.y = -particles[a].mass;		
	}
}

void setup() {
	setTitle("Gravity");
	for (int i = 0; i < numOfParticles; i++) {
		particles.push_back(particle());
	}
}

void loop() {
	coll();
	gravitate();
	loopGame();
	for (int i = 0; i < particles.size(); i++) {
		particles[i].move();
		particles[i].show();
	}
}
