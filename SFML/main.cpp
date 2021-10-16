#include <SFML/Graphics.hpp>
#include <iostream>
#include "windows.h"
#include <cstdlib>
#include <vector>

using namespace sf;
using namespace std;

class coord
{
public:

	coord(float x1, float y1) : x(x1), y(y1)
	{

	}
	float x;
	float y;
};

void contur()
{

}



int main()
{
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	// ќбъект, который, собственно, €вл€етс€ главным окном приложени€
	const int W = 500;
	const int H = 300;
	RenderWindow window(VideoMode(W, H), "SFML Works!", Style::Default, settings);
	window.clear(Color(20, 24, 10, 0));
	window.display();

	int k = 1, h = 0;
	Vertex line[100];
	line->color = Color::Blue;


	vector<float> vertex;
	vector<coord> vert;
	vector<coord> line_1;

	Event event;
	Vertex triangle[2];
	Vertex lines[2];

	Vertex triangle_2[2];
	// √лавный цикл приложени€. ¬ыполн€етс€, пока открыто окно
	while (window.isOpen())
	{
		// ќбрабатываем очередь событий в цикле
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)
			{
				window.close();
			}

			if (event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left)
			{
				sf::Vector2i position = sf::Mouse::getPosition(window);
				if (position.x <= 20 && position.y <= 20)
				{

					triangle[0] = Vertex(Vector2f(float(vert[0].x), float(vert[0].y)));

					//триангулировать из начальной точки
					//for (int g = 2; g < vert.size() - 1; ++g)
					//{
					//	
					//	triangle[1] = Vertex(Vector2f(float(vert[g].x), float(vert[g].y)));
					//	triangle->color = Color::Green;

					//	cout << "+====" << g << "====" << vert[g].x << "  " << vert[g].y << endl;
					//	
					//	window.draw(triangle, 2, Lines);
					//}
					//window.display();

					//ушной метод
					for (; vert.size() != 3;)
					{
						float n0_x = vert[0].x;
						float n0_y = vert[0].y;

						float n1_x = vert[1].x;
						float n1_y = vert[1].y;

						float n2_x = vert[2].x;
						float n2_y = vert[2].y;

						float n4_x = vert[vert.size() - 1].x;
						float n4_y = vert[vert.size() - 1].y;

						float deg4_0 = (n0_x * n4_x + n0_y * n4_y) / sqrt(pow(n0_x, 2) + pow(n0_y, 2)) + sqrt(pow(n4_x, 2) + pow(n4_y, 2));
						float deg1_0 = (n0_x * n1_x + n0_y * n1_y) / sqrt(pow(n0_x, 2) + pow(n0_y, 2)) + sqrt(pow(n1_x, 2) + pow(n1_y, 2));

						float vec4_0 = 

						//если угол больше закрываем "ухо"
						if (deg4_0 >= deg1_0)
						{
							triangle_2[0] = Vertex(Vector2f(float(vert[0].x), float(vert[0].y)));
							triangle_2[1] = Vertex(Vector2f(float(vert[2].x), float(vert[2].y)));
							triangle_2->color = Color::Green;
							window.draw(triangle_2, 2, Lines);
						}
						else
						{
							cout << "NOOOO" << endl;
						}

						window.display();
						//vert.erase(vert.begin()+1);
						break;
					}
				}
				else
				{
					window.clear(Color(20, 24, 10, 0));

					coord cord(float(position.x), float(position.y));
					vert.push_back(cord);
					line_1.push_back(cord);

					std::cout << "press" << k << ' ' << endl;
					++k;
					
					for (int i = 0; i < vert.size(); ++i)
					{
						if (i == vert.size() - 1)
						{
							lines[0] = Vertex(Vector2f(line_1[0].x, line_1[0].y));
							cout << line_1[0].x << ' ' << line_1[0].y << ' ' << endl;
							lines->color = Color::Blue;
							window.draw(lines, 2, Lines);
						}
						else
						{
							lines[0] = Vertex(Vector2f(line_1[i].x, vert[i].y));
							lines[1] = Vertex(Vector2f(line_1[i + 1].x, vert[i + 1].y));
							window.draw(lines, 2, Lines);
						}
					}

					RectangleShape rectangle(Vector2f(20.f, 20.f));
					rectangle.setFillColor(Color(12, 132, 14));
					window.draw(rectangle);
					window.display();
				}
			}
		}

		//window.display();
	}

	return 0;
}