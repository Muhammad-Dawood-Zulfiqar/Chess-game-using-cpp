//#include<SFML/Graphics.hpp>
//#include<SFML/Audio.hpp>
//#include"chess.h"
//#include<iostream>
///// <summary>
//
//
//
//
//
////swap krdena so transparent pieces are acceptable jis tarah abhi hai
//// takes function which when swaps changes taken piece ka Vector2i to (-99,-99)and changes its .t to 0 and makes .s transparent and then swaps like in current move animation
//// 
//// 
////piece ka vector2i bhi rkhwana naya;
////piece ka pointer is not correct in move animation so correct it.
//
//
//
//
//
///// </summary>
//using namespace std;
//using namespace sf;
//bool turn = 0;//can only be zero(for player white) or one(for player black)
//grids board[8][8];
//int click = 0;
//Player p1(1);
//Player p2(-1);
//
//Piece* pBoard[32];
//bool gameOver = 0;
//void game()
//{
//	SoundBuffer move;
//	SoundBuffer take;
//	SoundBuffer check;
//	SoundBuffer promote;
//	move.loadFromFile("move-self.mp3");
//	take.loadFromFile("capture.mp3");
//	check.loadFromFile("move-check.mp3");
//	promote.loadFromFile("promote.mp3");
//	Sound sound;
//	Vector2i pr(0, 0);
//	bool  a = 0;
//	Vector2i s1(0, 0);
//	RenderWindow window(VideoMode(800, 600), "CHESS");
//	window.setFramerateLimit(1000);
//	setTypeandAssignObjects(pBoard, board);
//	print2d(board);
//	Sprite promotion;
//	//making grid of sprites ith textures
//	Texture whiteknight, blackknight, whitequeen, blackqueen, whiteking, blackking, whitebishop, blackbishop, whiterook, blackrook, whitepawn, blackpawn, ipt, ipk,svg[13];
//	whiteknight.loadFromFile("wn.png");
//	blackknight.loadFromFile("bn.png");
//	whitebishop.loadFromFile("wb.png");
//	blackbishop.loadFromFile("bb.png");
//	whiterook.loadFromFile("wr.png");
//	blackrook.loadFromFile("br.png");
//	whiteking.loadFromFile("wk.png");
//	blackking.loadFromFile("bk.png");
//	whitequeen.loadFromFile("wq.png");
//	blackqueen.loadFromFile("bq.png");
//	whitepawn.loadFromFile("wp.png");
//	blackpawn.loadFromFile("bp.png");
//	ipk.loadFromFile("Picture1.png");
//	ipt.loadFromFile("ipt.png");
//	for (int i = 0; i < 13; i++)
//	{
//		if(i<10)
//		svg[i].loadFromFile("frame_00" + to_string(i) + "_delay-0.03s.png");
//		else
//		svg[i].loadFromFile("frame_0" + to_string(i) + "_delay-0.03s.png");
//	}
//	whiteknight.setSmooth(1);
//	blackknight.setSmooth(1);
//	whitebishop.setSmooth(1);
//	blackbishop.setSmooth(1);
//	whiterook.setSmooth(1);
//	blackrook.setSmooth(1);
//	whiteking.setSmooth(1);
//	blackking.setSmooth(1);
//	whitequeen.setSmooth(1);
//	blackqueen.setSmooth(1);
//	whitepawn.setSmooth(1);
//	blackpawn.setSmooth(1);
//	ipk.setSmooth(1);
//	ipt.setSmooth(1);
//	SetTextureA(board, whiteknight, blackknight, whitequeen, blackqueen, whiteking, blackking, whitebishop, blackbishop, whiterook, blackrook, whitepawn, blackpawn, ipk,ipt);
//	setPositionA(board, pBoard);
//
//
//	Texture boardback;
//	boardback.loadFromFile("chessboard2.jpg");
//	Texture overback;
//	overback.loadFromFile("dark-gray-wooden-plank-pattern.jpg");
//	Texture side;
//	side.loadFromFile("white-wooden-texture-flooring-background.jpg");
//
//	RectangleShape backgroundboard(Vector2f(800, 600));
//	backgroundboard.setPosition(Vector2f(0, 0));
//	backgroundboard.setTexture(&overback);
//
//	RectangleShape backgroundboard2(Vector2f(450, 450));
//	backgroundboard2.setPosition(Vector2f(75, 75));
//	backgroundboard2.setTexture(&boardback);
//
//	RectangleShape sideboard(Vector2f(300, 500));
//	sideboard.setPosition(Vector2f(530, 75));
////	sideboard.setTexture(&side);
//	sideboard.setFillColor(Color(255, 255, 255, 0));
//
//	Font sfont;
//	sfont.loadFromFile("Crima.ttf");
//	Text edofgm;
//	edofgm.setFont(sfont);
//	edofgm.setPosition(Vector2f(540, 250));
//	edofgm.setCharacterSize(20);
//	edofgm.setFillColor(Color::White);
//	edofgm.setString("WHITE'S TURN");
//
//	Text wtime;
//	wtime.setFont(sfont);
//	wtime.setPosition(Vector2f(540,400));
//	wtime.setCharacterSize(20);
//	wtime.setFillColor(Color::White);
//
//	Text btime;
//	btime.setFont(sfont);
//	btime.setPosition(Vector2f(540, 100));
//	btime.setCharacterSize(20);
//	btime.setFillColor(Color::White);
//
//
//	Texture t;
//	t.loadFromFile("Picture4.png");
//
//	sf::Clock clock;
//	double wduration = 600;
//	double bduration = 600;
//	wtime.setString("WHITE TIMER: " + std::to_string(600 / 60) + " : " + std::to_string(600 % 60));
//	btime.setString("BLACK TIMER: " + std::to_string(600 / 60) + " : " + std::to_string(600 % 60));
//
//	while (window.isOpen())
//	{
//		window.setFramerateLimit(1000);
//		sf::Time elapsed = clock.getElapsedTime();
//		if (!turn && !(gameOver) ){
//			int remainingtime= wduration - static_cast<int>(elapsed.asSeconds());
//			wtime.setString("WHITE TIMER: " + std::to_string(remainingtime / 60) + " : " + std::to_string(remainingtime % 60));
//		}
//		else if(turn &&!gameOver){
//			int remainingtime = bduration - static_cast<int>(elapsed.asSeconds());
//			btime.setString("BLACK TIMER: " + std::to_string(remainingtime / 60) + " : " + std::to_string(remainingtime % 60));
//
//		}
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed)
//			{
//				window.close();
//			}
//			else if (event.type == Event::MouseButtonPressed)
//			{
//				if (event.key.code == Mouse::Left)
//				{
//
//					Vector2f op(0, 0);
//					
//
//					if (click == 0) {
//
//						Vector2i mp = Mouse::getPosition(window);
//						s1 = convert(mp);
//						cout << "x: " << s1.x << endl;
//						cout << "y: " << s1.y << endl << endl;
//						if (s1.x >= 0 && s1.y >= 0 && s1.x <= 7 && s1.y <= 7) {
//							refresh(board, window, backgroundboard, backgroundboard2,sideboard, edofgm, wtime, btime);
//
//							if ((board[s1.x][s1.y].t < 0 && turn == 1) || (board[s1.x][s1.y].t > 0 && turn == 0)) {
//								illuminatepathchecker(s1, pBoard, board, turn, p1, p2, ipt, ipk);
//								refresh(board, window, backgroundboard, backgroundboard2,sideboard,edofgm,wtime,btime);
//								cout << click << endl;
//								click++;
//								cout << click << endl;
//							}
//						}
//
//					}
//					else if (click == 1) {
//						if (s1.x >= 0 && s1.y >= 0 && s1.x <= 7 && s1.y <= 7) {
//							Vector2i mp1 = convert(Mouse::getPosition(window));
//							Vector2i s2(mp1.x, mp1.y);
//							cout << "s2.x: " << s2.x << endl;
//							cout << "s2.y: " << s2.y << endl;
//							cout << click << endl;
//							if ((board[s2.x][s2.y].t <= 0 && turn == 0) || (board[s2.x][s2.y].t >= 0 && turn == 1)) {
//								DeleteIlluminatePath(board, t);
//								if (s1 != s2 && searchandreturnvalidmove(s1, s2, board, pBoard, turn)) {
//									pr = s2;
//									if (board[s1.x][s1.y].t == 6 || board[s1.x][s1.y].t == -6)
//									{
//										int i = 0;
//										i = findit(pBoard, s1);
//										pBoard[i]->setmovecounter(1);
//									}
//									if (board[s2.x][s2.y].t == 0) {
//										moveanimation(board, pBoard, s1, s2, window, backgroundboard, backgroundboard2, sideboard, edofgm, wtime, btime);
//										sound.setBuffer(move);
//										sound.play();
//										while (sound.getStatus() == sf::Sound::Playing) {
//											sf::sleep(sf::milliseconds(100)); // Sleep for a short duration
//										}
//
//										sound.stop();
//										if (board[s2.x][s2.y].t == -6 && s2.x == 7)
//										{
//											
//											promotion.setPosition(i_offset + tsx * s2.y, j_offset - 1.5 * tsy);
//											for (int i = 0; i < 13; i++)
//											{
//												svg[i].setSmooth(1);
//												op.x = svg[i].getSize().x;
//												op.y = (svg[i].getSize().y);
//												promotion.setScale(tsx * 5 / op.x, tsx * 1.125 / op.y);
//												promotion.setTexture(svg[i], 1);
//												refresh2(board, window, backgroundboard, backgroundboard2, promotion, sideboard, edofgm, wtime, btime);
//
//											}
//											click = 3;
//										}
//										else if (board[s2.x][s2.y].t == -6 && s2.x == 7)
//										{
//
//											promotion.setPosition(i_offset + tsx * s2.y, j_offset + 1.5 * tsy+s2.x*tsx);
//											for (int i = 0; i < 13; i++)
//											{
//												svg[i].setSmooth(1);
//												op.x = svg[i].getSize().x;
//												op.y = (svg[i].getSize().y);
//												promotion.setScale(tsx * 5 / op.x, tsx * 1.125 / op.y);
//												promotion.setTexture(svg[i], 1);
//												refresh2(board, window, backgroundboard, backgroundboard2, promotion, sideboard, edofgm, wtime, btime);
//
//											}
//											click = 3;
//
//
//										}
//									}
//									else {
//										takeanimation(board, pBoard, s1, s2, window, backgroundboard, backgroundboard2, sideboard, edofgm, wtime, btime);
//										sound.setBuffer(take);
//										sound.play();
//										while (sound.getStatus() == sf::Sound::Playing) {
//											sf::sleep(sf::milliseconds(100)); // Sleep for a short duration
//										}
//
//										sound.stop();
//										if (board[s2.x][s2.y].t == 6 && s2.x == 0)
//										{
//											
//											promotion.setPosition(i_offset + tsx * s2.y, j_offset - 1.5* tsy);
//											for (int i = 0; i < 13; i++)
//											{
//												svg[i].setSmooth(1);
//												op.x = svg[i].getSize().x;
//												op.y = (svg[i].getSize().y);
//												promotion.setScale(tsx * 5 / op.x, tsx * 1.125 / op.y);
//												promotion.setTexture(svg[i], 1);
//												refresh2(board, window, backgroundboard, backgroundboard2, promotion, sideboard, edofgm, wtime, btime);
//												
//											}
//											click = 3;
//											
//											
//										}
//										else if (board[s2.x][s2.y].t == -6 && s2.x == 7)
//										{
//
//											promotion.setPosition(i_offset + tsx * s2.y, j_offset + 1.5 * tsy+tsx*s2.x);
//											for (int i = 0; i < 13; i++)
//											{
//												svg[i].setSmooth(1);
//												op.x = svg[i].getSize().x;
//												op.y = (svg[i].getSize().y);
//												promotion.setScale(tsx * 5 / op.x, tsx * 1.125 / op.y);
//												promotion.setTexture(svg[i], 1);
//												refresh2(board, window, backgroundboard, backgroundboard2, promotion, sideboard, edofgm, wtime, btime);
//
//											}
//											click = 3;
//
//
//										}
//									}
//									
//									print2d(board);
//									if(click!=3)
//									turn = !turn;
//
//									if (incheck(pBoard[4]->getpos(), pBoard, 1, board) || incheck(pBoard[28]->getpos(), pBoard, 0, board)) {
//										sound.setBuffer(check);
//										sound.play();
//										while (sound.getStatus() == sf::Sound::Playing) {
//											sf::sleep(sf::milliseconds(100)); // Sleep for a short duration
//										}
//										sound.stop();
//									}
//									if (ischeckmate(pBoard, turn, board) || isstalemate(pBoard, turn, board)) {
//										gameOver = 1;
//										sound.setBuffer(check);
//										sound.play();
//										sound.stop();
//										if (ischeckmate(pBoard, turn, board)) {
//											if (turn) {
//												edofgm.setString("WHITE WINS BY CHECKMATE.");
//											}
//											else if (!turn) {
//												edofgm.setString("BLACK WINS BY CHECKMATE.");
//											}
//										}
//										else if (isstalemate(pBoard, turn, board)) {
//											edofgm.setString("DRAW BY STALEMATE.");
//										}
//									}
//									else {
//										if (turn) {
//											edofgm.setString("BLACK'S TURN");
//										}
//										else {
//											edofgm.setString("WHITE'S TURN");
//										}
//									}
//								
//									cout << click << endl;
//									cout << endl << "turn:" << turn << endl;
//								}
//							}
//
//						}
//						if(click!=3)
//						click = 0;
//						//cout << click << endl;
//						DeleteIlluminatePath(board, t);
//						refresh(board, window, backgroundboard, backgroundboard2, sideboard, edofgm, wtime, btime);
//
//					}
//					else if (click == 3)
//					{
//						bool donepr = 0;
//					
//							Vector2i mp = Mouse::getPosition(window);
//							cout << "x1: " << mp.x << endl;
//							cout << "y1: " << mp.y << endl;
//							Vector2i pro = convert(mp);
//							int k = findit(pBoard, pr);
//							int x = mp.x - (i_offset+(pr.y * tsx));
//							
//							cout << "x: " << x << endl;
//							if (pBoard[k]->gettype() == 6) {
//								delete pBoard[k];
//								if (mp.y <= 73 && mp.y >= 33) {
//									if (x <= 58 && x >= 18) {//wq
//										pBoard[k] = new Queen;
//										pBoard[k]->setpiece(pr.x,pr.y,2);
//										board[pr.x][pr.y].t = 2;
//										board[pr.x][pr.y].s.setTexture(whitequeen);
//										donepr = 1;
//									}
//									else if (x <= 99 && mp.x >= 72) {//wb
//										pBoard[k] = new Bishop;
//										pBoard[k]->setpiece(pr.x, pr.y, 3);
//										board[pr.x][pr.y].t = 3;
//										board[pr.x][pr.y].s.setTexture(whitebishop);
//										donepr = 1;
//									}
//									else if (x <= 150 && mp.x >= 110) {//wk
//										pBoard[k] = new Knight;
//										pBoard[k]->setpiece(pr.x, pr.y, 4);
//										board[pr.x][pr.y].t = 4;
//										board[pr.x][pr.y].s.setTexture(whiteknight);
//										donepr = 1;
//									}
//									else if (x <= 192 && mp.x >= 166) {//wr
//										pBoard[k] = new Rook;
//										pBoard[k]->setpiece(pr.x, pr.y, 5);
//										board[pr.x][pr.y].t = 5;
//										board[pr.x][pr.y].s.setTexture(whiterook);
//										donepr = 1;
//									}
//								}
//							}
//							if (pBoard[k]->gettype() == -6) {
//								delete pBoard[k];
//								if (mp.y <= 562 && mp.y >= 526) {
//									if (x <= 58 && x >= 18) {//bq
//										pBoard[k] = new Queen;
//										pBoard[k]->setpiece(pr.x, pr.y, -2);
//										board[pr.x][pr.y].t = -2;
//										board[pr.x][pr.y].s.setTexture(blackqueen);
//										donepr = 1;
//
//									}
//									else if (x <= 99 && mp.x >= 72) {//bb
//										pBoard[k] = new Bishop;
//										pBoard[k]->setpiece(pr.x, pr.y, -3);
//										board[pr.x][pr.y].t = -3;
//										board[pr.x][pr.y].s.setTexture(blackbishop);
//										donepr = 1;
//
//									}
//									else if (x <= 150 && mp.x >= 110) {//bk
//										pBoard[k] = new Knight;
//										pBoard[k]->setpiece(pr.x, pr.y, -4);
//										board[pr.x][pr.y].t = -4;
//										board[pr.x][pr.y].s.setTexture(blackknight);
//										donepr = 1;
//
//									}
//									else if (x <= 192 && mp.x >= 166) {//br
//										pBoard[k] = new Rook;
//										pBoard[k]->setpiece(pr.x, pr.y, -5);
//										board[pr.x][pr.y].t = -5;
//										board[pr.x][pr.y].s.setTexture(blackrook);
//										donepr = 1;
//
//									}
//								}
//							}
//						
//							if (donepr == 1) {
//								promotion.setTexture(t);
//								click = 0;
//								turn = !turn;
//								if (turn) {
//									edofgm.setString("BLACK'S TURN");
//								}
//								else {
//									edofgm.setString("WHITE'S TURN");
//								}
//								refresh2(board, window, backgroundboard, backgroundboard2, promotion, sideboard, edofgm, wtime, btime);
//								sound.setBuffer(promote);
//								sound.play();
//								while (sound.getStatus() == sf::Sound::Playing) {
//									sf::sleep(sf::milliseconds(100)); // Sleep for a short duration
//								}
//
//								sound.stop();
//							}
//					}
//	
//				}
//			}
//
//		}
//
//		window.clear();
//		window.draw(backgroundboard);
//		window.draw(backgroundboard2);
//		for (int i = 0; i < 8; i++) {
//			for (int j = 0; j < 8; j++)
//			{
//				window.draw(board[i][j].s);
//				window.draw(board[i][j].i);
//			}
//		}
//		window.draw(promotion);
//		window.draw(sideboard);
//		window.draw(edofgm);
//		window.draw(wtime);
//		window.draw(btime);
//		window.display();
//	}
//}
//void credits()
//{
//	//setting the background
//	sf::RenderWindow Credits(sf::VideoMode(1000, 720), "Credits");
//	sf::Texture credits;
//	sf::RectangleShape cdt(sf::Vector2f(1000, 720));
//	//credits.loadFromFile("C:\\Users\\g\\Desktop\\gems\\pxfuel.jpg");
//	//cdt.setTexture(&credits);
//	cdt.setFillColor(sf::Color(0, 0, 128));
//
//	sf::Text credit1, credit2;
//	sf::Font f;
//	f.loadFromFile("Crima.ttf");
//	credit1.setFont(f);
//	credit2.setFont(f);
//	credit1.setString("Abdullah Ahmad. Roll No: 23L-0629");
//	credit2.setString("Ch. Muhammad Dawood. Roll No: 23L-0918");
//	credit1.setPosition(sf::Vector2f(200, 150));
//	credit2.setPosition(sf::Vector2f(200, 350));
//	while (Credits.isOpen())
//	{
//		sf::Event event;
//		while (Credits.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//			{
//				Credits.close();
//
//			}
//		}
//		Credits.clear();
//		Credits.draw(cdt);
//		Credits.draw(credit1);
//		Credits.draw(credit2);
//		Credits.display();
//	}
//
//}
//int main()
//{
//	RenderWindow menu(VideoMode(800, 600), "CHESS");
//	menu.setFramerateLimit(30);
//
//	//Music m1;
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
//				while (frame2 < 61) {
//
//					background.setTexture(&tex2[frame2++]);
//					menu.clear();
//					menu.draw(background);
//					menu.display();
//				}
//
//				if (frame2 == 61)
//					menu.close();
//			}
//			else if (event.type == Event::MouseButtonPressed)
//			{
//				if (event.key.code == Mouse::Left)
//				{
//					Vector2i mp = Mouse::getPosition(menu);
//					if (mp.x > 609 && mp.x < 706 && mp.y>171 && mp.y < 215)//start
//					{
//						cout << "START" << endl;
//						while (frame2 < 61) {
//
//							background.setTexture(&tex2[frame2++]);
//							menu.clear();
//							menu.draw(background);
//							menu.display();
//						}
//
//						if (frame2 == 61)
//							menu.close();
//						
//						game();
//						
//					}
//					if (mp.x > 602 && mp.x < 723 && mp.y>226 && mp.y < 269)//credits
//					{
//						credits();
//
//						//menu.close();
//					}
//					if (mp.x > 620 && mp.x < 691 && mp.y>279 && mp.y < 323)//exit
//					{
//						cout << "EXIT" << endl;
//						while (frame2 < 61) {
//
//							background.setTexture(&tex2[frame2++]);
//							menu.clear();
//							menu.draw(background);
//							menu.display();
//						}
//
//						if (frame2 == 61)
//							menu.close();
//					}
//
//
//
//				}
//			}
//
//		}
//
//		if (frame < 50)
//			background.setTexture(&tex[frame++]);
//		else {
//			if (frame2 < 34)
//				background.setTexture(&tex2[frame2++]);
//		}
//		menu.clear();
//		menu.draw(background);
//		menu.display();
//	}
//
//}