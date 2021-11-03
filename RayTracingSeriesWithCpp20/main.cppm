import Renderer;
import <iostream>;
int main(int argc, char* argv[]) {
	//renderer::render();
	auto v1 = renderer::vec{2,3,1};
	auto v2 = renderer::vec{ 1,1,1 };
	std::cout << v1 + v2;
	return 0;
}