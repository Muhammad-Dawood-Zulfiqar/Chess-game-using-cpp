////#include<SFML/Graphics.hpp>
////#include<SFML/Audio.hpp>
////#include<iostream>
////
////using namespace std;
////using namespace sf;
////
//int main()
//{
//	RenderWindow menu(VideoMode(800, 600), "CHESS");
//	menu.setFramerateLimit(30);
//
//	Music m1;
//	int frame = 0;
//	int frame2 = 0;
//
//	RectangleShape background(Vector2f(800, 600));
//	background.setPosition(Vector2f(0, 0));
//	Texture tex[50], tex2[61];
//
//	for (int i = 0; i < 50; i++)
//	{
//		tex[i].loadFromFile("frame (" + to_string(i + 1) + ").jpg");
//	}
//	background.setTexture(&tex[0]);
//
//	for (int i = 0; i < 33; i++)
//	{
//		tex2[i].loadFromFile("frame3 (" + to_string(i + 1) + ").jpg");
//	}
//	tex2[33].loadFromFile("frame3 (34).png");
//
//	for (int i = 34; i < 61; i++)
//	{
//		tex2[i].loadFromFile("frame3 (" + to_string(i + 1) + ").jpg");
//	}
//
//
//	while (menu.isOpen())
//	{
//		sf::Event event;
//		while (menu.pollEvent(event))
//		{
//			if (event.type == Event::Closed)
//			{
//				while (frame2 < 61){
//
//				background.setTexture(&tex2[frame2++]);
//				menu.clear();
//				menu.draw(background);
//				menu.display();
//			}
//				
//				if(frame2==61)
//				menu.close();
//			}
//			else if (event.type == Event::MouseButtonPressed)
//			{
//				if (event.key.code == Mouse::Left)
//				{
//					Vector2i mp = Mouse::getPosition(menu);
//					if (mp.x > 609 && mp.x < 706 && mp.y>171 && mp.y < 215)//start
//					{
//						cout << "START" << endl;
//						//menu.close();
//					}
//					if (mp.x > 602 && mp.x < 723 && mp.y>226 && mp.y < 269)//credits
//					{
//						cout << "Credits" << endl;
//
//						//menu.close();
//					}
//					if (mp.x > 620 && mp.x < 691 && mp.y>279 && mp.y < 323)//exit
//					{
//						cout << "EXIT" << endl;
//						menu.close();
//					}
//
//
//
//				}
//			}
//
//		}
//		
//		if(frame<50)
//		background.setTexture(&tex[frame++]);
//		else {
//			if(frame2<34)
//			background.setTexture(&tex2[frame2++]);
//		}
//		menu.clear();
//		menu.draw(background);
//		menu.display();
//	}
//	
//}