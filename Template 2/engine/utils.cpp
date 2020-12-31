float dist(float x1, float y1, float x2, float y2) {
	float distance = sqrt(((x1 - x2)*(x1 - x2)) + ((y1 - y2)*(y1 - y2)));
	if (distance < 0) distance *= -1;
	return distance;
}
float average(float _a, float _b) {
	return (_a + _b) / 2;
}
Vector createVector(float x, float y) {
	Vector v;
	v.x = x;
	v.y = y;
	return v;
}
int roundV(float x) {
	int decRemoved = (int)x;
	float rem = x - decRemoved;
	if (rem < 0.5)
		return decRemoved;
	else
		return decRemoved + 1;
}