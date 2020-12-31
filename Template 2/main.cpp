void setup(void) {
	setTitle("Template");
}
void loop(void) {
	fill(255, 0, 0, 255);
	ellipse(
		width / 2, height / 2,
		min(width, height) / 2,
		min(width, height) / 4
	);
}
