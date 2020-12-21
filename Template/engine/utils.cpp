int getSmaller(int a, int b) {
	if (a < b) return a;
	else return b;
}
int getLarger(int a, int b) {
	if (a > b) return a;
	else return b;
}
float dist(float x1, float y1, float x2, float y2) {
	float distance = sqrt(((x1 - x2)*(x1 - x2)) + ((y1 - y2)*(y1 - y2)));
	if (distance < 0) distance *= -1;
	return distance;
}
float average(float _a, float _b) {
	return (_a + _b) / 2;
}
