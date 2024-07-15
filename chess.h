//#pragma once
//#include<iostream>
//#include<SFML/Graphics.hpp>
//using namespace std;
//using namespace sf;
//
//int tsy = 49;//tile size
//int tsx = 49;//tile size
//float i_offset = 103;//initial offset of grid from left side of window
//float j_offset = 103;//initial offset of grid from top side of window
//
//
//struct grids {
//	int t;
//	Sprite s;
//	Sprite i;
//};
//
//
//
//void DeleteIlluminatePath(grids board[8][8], Texture& t)
//{
//
//
//	for (int i = 0; i < 8; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//
//			board[i][j].i.setTexture(t);
//
//		}
//	}
//}
//
//struct Player;
//class Piece {
//protected:int x, y, type; Vector2i s1; int movecounter = 0;
//public:
//
//	Piece() {
//		x = 0;
//		y = 0;
//		s1.x = 0; s1.y = 0;
//	}
//	//constructor all types
//	//destructor
//	bool castle();//tbc in move
//	bool take();//tbc in move
//	bool inpath();//tbc in move and take
//	bool enpassant();//tbc in take
//	bool select();//tbc in move
//	virtual void illuminatepath(Vector2i s1, Texture& ipt, Texture& ipk, Piece* pBoard[], grids board[][8], bool turn) {};//tbc in select
//	void illuminatetarget();//tbc in select
//	virtual bool validmove(Vector2i s2, Piece* pBoard[], bool turn, grids board[][8]) { return 0; }//tbc in move(check functions for each piece) also polymorphism since checks differ for each piece
//	virtual void move() = 0;//conducted through polymorphism
//	void highlightprevspot();//tbc in move
//
//	virtual bool validMove1(Vector2i s2) { return 0; }
//
//	void setpiece(int i, int j, int t) {
//		s1.x = i;
//		s1.y = j;
//		type = t;
//	}
//	int gettype()
//	{
//		return type;
//	}
//	Vector2i getpos() {
//		return s1;
//	}
//	void setpos(Vector2i c) {
//		s1 = c;
//	}
//	void settype(int ty) {
//		type = ty;
//	}
//	void setmovecounter(int x)
//	{
//		movecounter = x;
//	}
//
//	friend void setTypeandAssignObjects(Piece* a[], grids board[8][8]);
//
//};
//
//bool incheck(Vector2i kingPos, Piece* pBoard[], bool turn, grids board[][8])
//{
//	for (int i = 0; i < 32; i++)
//	{
//
//
//		if (turn == 0 && pBoard[i]->gettype() < -1 && pBoard[i]->gettype() != -6) {
//			if (pBoard[i]->validmove(kingPos, pBoard, turn, board)) {
//				return true;
//			}
//		}
//		else if (turn == 0 && pBoard[i]->gettype() < -1 && pBoard[i]->gettype() == -6)
//		{
//			if (kingPos.x == pBoard[i]->getpos().x + 1 && (kingPos.y == pBoard[i]->getpos().y + 1 || kingPos.y == pBoard[i]->getpos().y - 1))
//				return true;
//		}
//		else if (turn == 1 && pBoard[i]->gettype() > 1&&pBoard[i]->gettype()  !=6) {
//			if (pBoard[i]->validmove(kingPos, pBoard, turn, board)) {
//				return true;
//			}
//		}
//		else if (turn == 1 && pBoard[i]->gettype() > 1 && pBoard[i]->gettype() == 6)
//		{
//			if (kingPos.x == pBoard[i]->getpos().x - 1 && (kingPos.y == pBoard[i]->getpos().y + 1 || kingPos.y == pBoard[i]->getpos().y - 1))
//				return true;
//		}
//		else if (turn == 1 && pBoard[i]->gettype() == 1)
//		{
//			if (pBoard[i]->validMove1(kingPos))
//			{
//				return 1;
//			}
//		}
//		else if (turn == 0 && pBoard[i]->gettype() == -1)
//		{
//
//			if (pBoard[i]->validMove1(kingPos))
//			{
//				return 1;
//			}
//		}
//
//	}
//	return false;
//}
//int findit(Piece* pBoard[], Vector2i s1)
//{
//	for (int i = 0; i < 32; i++) {
//		if (pBoard[i]->getpos() == s1)
//		{
//			return i;
//		}
//
//	}
//	return -1;
//}
//
//Vector2i getkingpos(Piece* pBoard[], bool turn) {
//	Vector2i KingPos(0, 0);
//	for (int i = 0; i < 32; i++)
//	{
//		if (turn == 0 && pBoard[i]->gettype() == 1)
//		{
//			KingPos = pBoard[i]->getpos();
//			break;
//		}
//		if (turn == 1 && pBoard[i]->gettype() == -1) {
//			KingPos = pBoard[i]->getpos();
//			break;
//		}
//	}
//	return KingPos;
//}
//
//
//bool ispinned(Piece* pBoard[], bool turn, grids board[][8], Vector2i s1, Vector2i s2) {
//	Vector2i ex(-99, -99);
//	Vector2i KingPos = getkingpos(pBoard, turn);
//	int i = findit(pBoard, s1);
//	bool flag = 0;
//	if (i != -1) {
//		if (pBoard[i]->validmove(s2, pBoard, turn, board)/* && !incheck(KingPos, pBoard, turn, board)*/)
//		{
//			int x = pBoard[i]->gettype();
//			int f = findit(pBoard, s2);
//			pBoard[i]->setpos(s2);
//			int y = 0;
//			if (f != -1) {
//				y = pBoard[f]->gettype();
//				pBoard[f]->settype(0);
//				pBoard[f]->setpos(ex);
//			}
//			board[s2.x][s2.y].t = x;
//			board[s1.x][s1.y].t = 0;
//			KingPos = getkingpos(pBoard, turn);
//			//print2d(board);
//			//printpBoard(pBoard);
//			if (incheck(KingPos, pBoard, turn, board)) {
//
//				flag = 1;
//			}
//			if (f != -1) {
//				pBoard[f]->setpos(s2);
//				pBoard[f]->settype(y);
//			}
//			pBoard[i]->setpos(s1);
//			board[s2.x][s2.y].t = y;
//			board[s1.x][s1.y].t = x;
//
//		}
//	}
//
//	return flag;
//}
//
//struct Player {
//	int score;
//	int color;//black -1 and white 1;
//	bool ischeckmate() {};
//	bool isstalemate()
//	{
//
//	}
//	Player(int x) { color = x; }
//};
//
//bool isvalidKing(Vector2i s1, Vector2i s2, Piece* pBoard[], bool turn, grids board[][8])
//{
//	bool mark = 0;
//	if (((s2.x == s1.x + 1 && s1.y == s2.y) && ((!incheck(s2, pBoard, turn, board))))
//		|| ((s2.x == s1.x - 1 && s1.y == s2.y) && ((!incheck(s2, pBoard, turn, board))))
//		|| ((s2.x == s1.x && s1.y == s2.y + 1) && ((!incheck(s2, pBoard, turn, board))))
//		|| ((s2.x == s1.x && s1.y == s2.y - 1) && ((!incheck(s2, pBoard, turn, board))))
//		|| ((s2.x == s1.x + 1 && s1.y == s2.y + 1) && ((!incheck(s2, pBoard, turn, board))))
//		|| ((s2.x == s1.x + 1 && s1.y == s2.y - 1) && ((!incheck(s2, pBoard, turn, board))))
//		|| ((s2.x == s1.x - 1 && s1.y == s2.y + 1) && ((!incheck(s2, pBoard, turn, board))))
//		|| ((s2.x == s1.x - 1 && s1.y == s2.y - 1) && ((!incheck(s2, pBoard, turn, board)))))
//	{
//		mark = 1;
//	}
//	return mark;
//}
//
//bool ValidKingWithoutIncheck(Vector2i s1, Vector2i s2)
//{
//	bool mark = 0;
//	if ((s2.x == s1.x + 1 && s1.y == s2.y)
//		|| (s2.x == s1.x - 1 && s1.y == s2.y)
//		|| (s2.x == s1.x && s1.y == s2.y + 1)
//		|| (s2.x == s1.x && s1.y == s2.y - 1)
//		|| (s2.x == s1.x + 1 && s1.y == s2.y + 1)
//		|| (s2.x == s1.x + 1 && s1.y == s2.y - 1)
//		|| (s2.x == s1.x - 1 && s1.y == s2.y + 1)
//		|| (s2.x == s1.x - 1 && s1.y == s2.y - 1))
//	{
//		mark = 1;
//	}
//	return mark;
//}
//bool isValidRook(Vector2i s1, Vector2i s2, grids board[8][8])
//{
//	bool mark = 1;
//	if (s1.x != s2.x && s1.y == s2.y)
//	{
//		if (s1.x > s2.x)
//		{
//			for (int i = s2.x + 1; i < s1.x; i++)
//			{
//				if (board[i][s1.y].t != 0)
//					mark = 0;
//			}
//
//		}
//		if (s1.x < s2.x)
//		{
//			for (int i = s1.x + 1; i < s2.x; i++)
//			{
//				if (board[i][s1.y].t != 0)
//					mark = 0;
//			}
//
//		}
//	}
//	else if (s1.x == s2.x && s1.y != s2.y)
//	{
//		if (s1.y > s2.y)
//		{
//			for (int i = s2.y + 1; i < s1.y; i++)
//			{
//				if (board[s1.x][i].t != 0)
//					mark = 0;
//			}
//
//		}
//		if (s1.y < s2.y)
//		{
//			for (int i = s1.y + 1; i < s2.y; i++)
//			{
//				if (board[s1.x][i].t != 0)
//					mark = 0;
//			}
//		}
//	}
//	else
//	{
//		mark = 0;
//
//	}
//	return mark;
//}
//bool isValidKnight(Vector2i s1, Vector2i s2)
//{
//	bool mark = 0;
//	if ((s2.x == s1.x + 1 && s2.y == s1.y + 2) || (s2.x == s1.x - 1 && s2.y == s1.y + 2) || (s2.x == s1.x + 2 && s2.y == s1.y + 1) || (s2.x == s1.x + 2 && s2.y == s1.y - 1) || (s2.x == s1.x - 2 && s2.y == s1.y + 1) || (s2.x == s1.x - 2 && s2.y == s1.y - 1) || (s2.x == s1.x + 1 && s2.y == s1.y - 2) || (s2.x == s1.x - 1 && s2.y == s1.y - 2))
//	{
//		mark = 1;
//	}
//	return mark;
//}
//
//
//bool diagonal(grids board[][8], Vector2i s1, Vector2i s2)
//{
//	// check if code chawwali
//	bool flag = 1;
//	if ((abs(s1.x - s2.x) != abs(s1.y - s2.y)) || abs(s1.x - s2.x) == 0)
//		flag = 0;
//
//	int dx = 0;
//	int dy = 0;
//	if (s2.x - s1.x > 0)
//		dx = 1;
//	else
//		dx = -1;
//
//	if (s2.y - s1.y > 0)
//		dy = 1;
//	else
//		dy = -1;
//
//	int i = s1.x + dx;
//	int j = s1.y + dy;
//	while (i != s2.x && j != s2.y && flag != 0) {
//		if (board[i][j].t != 0)
//			flag = 0;
//		i += dx;
//		j += dy;
//	}
//	return flag;
//}
//
//
//class King :public Piece {
//private://to  check for castling
//public:
//	King() {}
//	//constructor all types
//	//destructor
//	bool validmove(Vector2i s2, Piece* pBoard[], bool turn, grids board[][8]) {
//		if (s2.x >= 0 && s2.y >= 0 && s2.x <= 7 && s2.y <= 7) {
//
//			return isvalidKing(s1, s2, pBoard, turn, board);
//		}
//		else
//			return false;
//	}
//	//exception handling
//	void illuminatepath(Vector2i s1, Texture& ipt, Texture& ipk, Piece* pBoard[], grids board[][8], bool turn)//ipt=illuminate path texture i.e a dot in tranpaernt image, ipk=illuminate path kill
//	{
//
//
//
//		//works for preloaded textures passed through it 
//		Vector2i s2;
//		s2.x = s1.x + 1;
//		s2.y = s1.y;
//		if (s1.x < 7 && ((turn == 0 && board[s1.x + 1][s1.y].t < 0) || (turn == 1 && board[s1.x + 1][s1.y].t > 0)) && (!incheck(s2, pBoard, turn, board)))
//		{
//			board[s1.x + 1][s1.y].i.setTexture(ipk);
//
//
//		}
//		else if (s1.x < 7 && board[s1.x + 1][s1.y].t == 0 && (!incheck(s2, pBoard, turn, board)))
//		{
//			board[s1.x + 1][s1.y].i.setTexture(ipt);
//		}
//
//		s2.x = s1.x - 1;
//		s2.y = s1.y;
//
//		if (s1.x > 0 && ((turn == 0 && board[s1.x - 1][s1.y].t < 0) || (turn == 1 && board[s1.x - 1][s1.y].t > 0)) && (!incheck(s2, pBoard, turn, board)))
//		{
//			board[s1.x - 1][s1.y].i.setTexture(ipk);
//		}
//		else if (s1.x > 0 && board[s1.x - 1][s1.y].t == 0 && (!incheck(s2, pBoard, turn, board)))
//		{
//			board[s1.x - 1][s1.y].i.setTexture(ipt);
//		}
//
//		s2.x = s1.x;
//		s2.y = s1.y + 1;
//		if (s1.y < 7 && ((turn == 0 && board[s1.x][s1.y + 1].t < 0) || (turn == 1 && board[s1.x][s1.y + 1].t > 0)) && (!incheck(s2, pBoard, turn, board)))
//		{
//			board[s1.x][s1.y + 1].i.setTexture(ipk);
//		}
//		else if (s1.y < 7 && board[s1.x][s1.y + 1].t == 0 && (!incheck(s2, pBoard, turn, board)))
//		{
//			board[s1.x][s1.y + 1].i.setTexture(ipt);
//		}
//
//		s2.x = s1.x;
//		s2.y = s1.y - 1;
//		if (s1.y > 0 && ((turn == 0 && board[s1.x][s1.y - 1].t < 0) || (turn == 1 && board[s1.x][s1.y - 1].t > 0)) && (!incheck(s2, pBoard, turn, board)))
//		{
//			board[s1.x][s1.y - 1].i.setTexture(ipk);
//		}
//		else if (s1.y > 0 && board[s1.x][s1.y - 1].t == 0 && (!incheck(s2, pBoard, turn, board)))
//		{
//			board[s1.x][s1.y - 1].i.setTexture(ipt);
//		}
//
//
//		s2.x = s1.x + 1;
//		s2.y = s1.y + 1;
//		if (s1.y < 7 && s1.x < 7 && ((turn == 0 && board[s1.x + 1][s1.y + 1].t < 0) || (turn == 1 && board[s1.x + 1][s1.y + 1].t > 0)) && (!incheck(s2, pBoard, turn, board)))
//		{
//			board[s1.x + 1][s1.y + 1].i.setTexture(ipk);
//		}
//		else if (s1.y < 7 && s1.x < 7 && board[s1.x + 1][s1.y + 1].t == 0 && (!incheck(s2, pBoard, turn, board)))
//		{
//			board[s1.x + 1][s1.y + 1].i.setTexture(ipt);
//		}
//
//
//		s2.x = s1.x + 1;
//		s2.y = s1.y - 1;
//		if (s1.y > 0 && s1.x < 7 && ((turn == 0 && board[s1.x + 1][s1.y - 1].t < 0) || (turn == 1 && board[s1.x + 1][s1.y - 1].t > 0)) && (!incheck(s2, pBoard, turn, board)))
//		{
//			board[s1.x + 1][s1.y - 1].i.setTexture(ipk);
//		}
//		else if (s1.y > 0 && s1.x < 7 && board[s1.x + 1][s1.y - 1].t == 0 && (!incheck(s2, pBoard, turn, board)))
//		{
//			board[s1.x + 1][s1.y - 1].i.setTexture(ipt);
//		}
//
//
//		s2.x = s1.x - 1;
//		s2.y = s1.y + 1;
//		if (s1.y < 7 && s1.x>0 && ((turn == 0 && board[s1.x - 1][s1.y + 1].t < 0) || (turn == 1 && board[s1.x - 1][s1.y + 1].t > 0)) && (!incheck(s2, pBoard, turn, board)))
//		{
//			board[s1.x - 1][s1.y + 1].i.setTexture(ipk);
//		}
//		else if (s1.y < 7 && s1.x>0 && board[s1.x - 1][s1.y + 1].t == 0 && (!incheck(s2, pBoard, turn, board)))
//		{
//			board[s1.x - 1][s1.y + 1].i.setTexture(ipt);
//		}
//
//
//		s2.x = s1.x - 1;
//		s2.y = s1.y - 1;
//		if (s1.y > 0 && s1.x > 0 && ((turn == 0 && board[s1.x - 1][s1.y - 1].t < 0) || (turn == 1 && board[s1.x - 1][s1.y - 1].t > 0)) && (!incheck(s2, pBoard, turn, board)))
//		{
//			board[s1.x - 1][s1.y - 1].i.setTexture(ipk);
//		}
//		else if (s1.y > 0 && s1.x > 0 && board[s1.x - 1][s1.y - 1].t == 0 && (!incheck(s2, pBoard, turn, board)))
//		{
//			board[s1.x - 1][s1.y - 1].i.setTexture(ipt);
//		}
//
//	}
//	void move() {
//
//	}
//	bool validMove1(Vector2i s2)
//	{
//		if (s2.x >= 0 && s2.y >= 0 && s2.x <= 7 && s2.y <= 7) {
//			if (ValidKingWithoutIncheck(s1, s2))
//				return 1;
//			else
//				return 0;
//		}
//		else
//			return 0;
//	}
//};
//
//class Queen :public Piece {
//public:
//	Queen() {}
//
//	//constructor all types
//	//destructor
//	bool validmove(Vector2i s2, Piece* pBoard[], bool turn, grids board[][8]) {
//		if (s2.x >= 0 && s2.y >= 0 && s2.x <= 7 && s2.y <= 7) {
//
//			bool flag = (isValidRook(s1, s2, board) || diagonal(board, s1, s2));
//			return flag;
//		}
//		else
//			return false;
//	}
//	void illuminatepath(Vector2i s1, Texture& ipt, Texture& ipk, Piece* pBoard[], grids board[][8], bool turn)//ipt=illuminate path texture i.e a dot in tranpaernt image, ipk=illuminate path kill
//	{
//		//bishop part
//		bool flag = 1;
//		Vector2i s2;
//		for (int i = s1.x + 1, j = s1.y + 1; i < 8 && j < 8 && i >= 0 && j >= 0 && flag == 1; i++, j++)
//		{
//			s2.x = i;
//			s2.y = j;
//			if (board[i][j].t == 0 && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[i][j].i.setTexture(ipt);
//			}
//			else if (((turn == 0 && board[i][j].t < 0) || (turn == 1 && board[i][j].t > 0)) && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[i][j].i.setTexture(ipk);
//				flag = 0;
//			}
//			else
//			{
//				flag = 0;
//			}
//		}
//		flag = 1;
//		for (int i = s1.x + 1, j = s1.y - 1; i < 8 && j < 8 && i >= 0 && j >= 0 && flag == 1; i++, j--)
//		{
//
//			s2.x = i;
//			s2.y = j;
//			if (board[i][j].t == 0 && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[i][j].i.setTexture(ipt);
//			}
//			else if (((turn == 0 && board[i][j].t < 0) || (turn == 1 && board[i][j].t > 0)) && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[i][j].i.setTexture(ipk);
//				flag = 0;
//			}
//			else
//			{
//				flag = 0;
//			}
//		}
//		flag = 1;
//
//		for (int i = s1.x - 1, j = s1.y + 1; i < 8 && j < 8 && i >= 0 && j >= 0 && flag == 1; i--, j++)
//		{
//
//			s2.x = i;
//			s2.y = j;
//			if (board[i][j].t == 0 && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[i][j].i.setTexture(ipt);
//			}
//			else if (((turn == 0 && board[i][j].t < 0) || (turn == 1 && board[i][j].t > 0)) && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[i][j].i.setTexture(ipk);
//				flag = 0;
//			}
//			else
//			{
//				flag = 0;
//			}
//		}
//		flag = 1;
//
//		for (int i = s1.x - 1, j = s1.y - 1; i < 8 && j < 8 && i >= 0 && j >= 0 && flag == 1; i--, j--)
//		{
//
//			s2.x = i;
//			s2.y = j;
//			if (board[i][j].t == 0 && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[i][j].i.setTexture(ipt);
//			}
//			else if (((turn == 0 && board[i][j].t < 0) || (turn == 1 && board[i][j].t > 0)) && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[i][j].i.setTexture(ipk);
//				flag = 0;
//			}
//			else
//			{
//				flag = 0;
//			}
//		}
//
//
//
//
//		//rook part
//		flag = 1;
//		for (int i = s1.x + 1; i < 8 && i >= 0 && flag == 1; i++)
//		{
//			s2.x = i;
//			s2.y = s1.y;
//			if (board[i][s1.y].t == 0 && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[i][s1.y].i.setTexture(ipt);
//			}
//			else if (((turn == 0 && board[i][s1.y].t < 0) || (turn == 1 && board[i][s1.y].t > 0)) && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[i][s1.y].i.setTexture(ipk);
//				flag = 0;
//			}
//			else
//			{
//				flag = 0;
//			}
//		}
//		flag = 1;
//		for (int i = s1.x - 1; i < 8 && i >= 0 && flag == 1; i--)
//		{
//
//			s2.x = i;
//			s2.y = s1.y;
//			if (board[i][s1.y].t == 0 && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[i][s1.y].i.setTexture(ipt);
//			}
//			else if (((turn == 0 && board[i][s1.y].t < 0) || (turn == 1 && board[i][s1.y].t > 0)) && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[i][s1.y].i.setTexture(ipk);
//				flag = 0;
//			}
//			else
//			{
//				flag = 0;
//			}
//		}
//		flag = 1;
//		for (int i = s1.y + 1; i < 8 && i >= 0 && flag == 1; i++)
//		{
//
//			s2.x = s1.x;
//			s2.y = i;
//			if (board[s1.x][i].t == 0 && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[s1.x][i].i.setTexture(ipt);
//			}
//			else if (((turn == 0 && board[s1.x][i].t < 0) || (turn == 1 && board[s1.x][i].t > 0)) && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[s1.x][i].i.setTexture(ipk);
//				flag = 0;
//			}
//			else
//			{
//				flag = 0;
//			}
//		}
//
//		flag = 1;
//		for (int i = s1.y - 1; i < 8 && i >= 0 && flag == 1; i--)
//		{
//
//			s2.x = s1.x;
//			s2.y = i;
//			if (board[s1.x][i].t == 0 && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[s1.x][i].i.setTexture(ipt);
//			}
//			else if (((turn == 0 && board[s1.x][i].t < 0) || (turn == 1 && board[s1.x][i].t > 0)) && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[s1.x][i].i.setTexture(ipk);
//				flag = 0;
//			}
//			else
//			{
//				flag = 0;
//			}
//		}
//	}
//
//
//	void move() {
//
//	}
//};
//
//class Bishop :public Piece {
//public:
//	Bishop() {}
//	//constructor all types
//	//destructor
//	bool validmove(Vector2i s2, Piece* pBoard[], bool turn, grids board[][8])
//	{
//		if (s2.x >= 0 && s2.y >= 0 && s2.x <= 7 && s2.y <= 7) {
//			return diagonal(board, s1, s2);
//		}
//		else
//			return 0;
//	}
//	void illuminatepath(Vector2i s1, Texture& ipt, Texture& ipk, Piece* pBoard[], grids board[][8], bool turn)//ipt=illuminate path texture i.e a dot in tranpaernt image, ipk=illuminate path kill
//	{
//
//		//bishop part
//		bool flag = 1;
//		Vector2i s2;
//		for (int i = s1.x + 1, j = s1.y + 1; i < 8 && j < 8 && i >= 0 && j >= 0 && flag == 1; i++, j++)
//		{
//
//			s2.x = i;
//			s2.y = j;
//			if (board[i][j].t == 0 && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[i][j].i.setTexture(ipt);
//			}
//			else if (((turn == 0 && board[i][j].t < 0) || (turn == 1 && board[i][j].t > 0)) && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[i][j].i.setTexture(ipk);
//				flag = 0;
//			}
//			else
//			{
//				flag = 0;
//			}
//		}
//		flag = 1;
//		for (int i = s1.x + 1, j = s1.y - 1; i < 8 && j < 8 && i >= 0 && j >= 0 && flag == 1; i++, j--)
//		{
//
//			s2.x = i;
//			s2.y = j;
//			if (board[i][j].t == 0 && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[i][j].i.setTexture(ipt);
//			}
//			else if (((turn == 0 && board[i][j].t < 0) || (turn == 1 && board[i][j].t > 0)) && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[i][j].i.setTexture(ipk);
//				flag = 0;
//			}
//			else
//			{
//				flag = 0;
//			}
//		}
//		flag = 1;
//
//		for (int i = s1.x - 1, j = s1.y + 1; i < 8 && j < 8 && i >= 0 && j >= 0 && flag == 1; i--, j++)
//		{
//
//			s2.x = i;
//			s2.y = j;
//			if (board[i][j].t == 0 && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[i][j].i.setTexture(ipt);
//			}
//			else if (((turn == 0 && board[i][j].t < 0) || (turn == 1 && board[i][j].t > 0)) && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[i][j].i.setTexture(ipk);
//				flag = 0;
//			}
//			else
//			{
//				flag = 0;
//			}
//		}
//		flag = 1;
//
//		for (int i = s1.x - 1, j = s1.y - 1; i < 8 && j < 8 && i >= 0 && j >= 0 && flag == 1; i--, j--)
//		{
//
//			s2.x = i;
//			s2.y = j;
//			if (board[i][j].t == 0 && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[i][j].i.setTexture(ipt);
//			}
//			else if (((turn == 0 && board[i][j].t < 0) || (turn == 1 && board[i][j].t > 0)) && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[i][j].i.setTexture(ipk);
//				flag = 0;
//			}
//			else
//			{
//				flag = 0;
//			}
//		}
//
//
//
//	}
//
//	void move() {
//
//	}
//};
//
//class Knight :public Piece {
//public:
//	Knight() {}
//	//constructor all types
//	//destructor
//	bool validmove(Vector2i s2, Piece* pBoard[], bool turn, grids board[][8]) {
//		if (s2.x >= 0 && s2.y >= 0 && s2.x <= 7 && s2.y <= 7) {
//
//			return isValidKnight(s1, s2);
//		}
//		else
//			return 0;
//	}
//
//	void illuminatepath(Vector2i s1, Texture& ipt, Texture& ipk, Piece* pBoard[], grids board[][8], bool turn)//ipt=illuminate path texture i.e a dot in tranpaernt image, ipk=illuminate path kill
//	{
//		Vector2i s2;
//		s2.x = s1.x + 1;
//		s2.y = s1.y + 2;
//
//
//		if (s1.x <= 6 && s1.y <= 5 && board[s1.x + 1][s1.y + 2].t == 0 && !ispinned(pBoard, turn, board, s1, s2))
//		{
//			board[s1.x + 1][s1.y + 2].i.setTexture(ipt);
//
//		}
//		else if (s1.x < 7 && s1.y < 6 && (board[s1.x + 1][s1.y + 2].t != 0) && ((turn == 0 && board[s1.x + 1][s1.y + 2].t < 0) || (turn == 1 && board[s1.x + 1][s1.y + 2].t > 0)) && !ispinned(pBoard, turn, board, s1, s2))
//		{
//			board[s1.x + 1][s1.y + 2].i.setTexture(ipk);
//
//		}
//		s2.x = s1.x - 1;
//		s2.y = s1.y + 2;
//
//		if (s1.x > 0 && s1.y < 6 && board[s1.x - 1][s1.y + 2].t == 0 && !ispinned(pBoard, turn, board, s1, s2))
//		{
//			board[s1.x - 1][s1.y + 2].i.setTexture(ipt);
//
//		}
//		else if (s1.x > 0 && s1.y < 6 && (board[s1.x - 1][s1.y + 2].t != 0) && ((turn == 0 && board[s1.x - 1][s1.y + 2].t < 0) || (turn == 1 && board[s1.x - 1][s1.y + 2].t > 0)) && !ispinned(pBoard, turn, board, s1, s2))
//		{
//			board[s1.x - 1][s1.y + 2].i.setTexture(ipk);
//
//		}
//
//		s2.x = s1.x + 2;
//		s2.y = s1.y + 1;
//
//		if (s1.x <= 5 && s1.y <= 6 && board[s1.x + 2][s1.y + 1].t == 0 && !ispinned(pBoard, turn, board, s1, s2))
//		{
//			board[s1.x + 2][s1.y + 1].i.setTexture(ipt);
//
//		}
//		else if (s1.x <= 5 && s1.y <= 6 && ((turn == 0 && board[s1.x + 2][s1.y + 1].t < 0) || (turn == 1 && board[s1.x + 2][s1.y + 1].t > 0)) && !ispinned(pBoard, turn, board, s1, s2))
//		{
//			board[s1.x + 2][s1.y + 1].i.setTexture(ipk);
//
//		}
//
//
//		s2.x = s1.x + 2;
//		s2.y = s1.y - 1;
//		if (s1.x < 6 && s1.y > 0 && board[s1.x + 2][s1.y - 1].t == 0 && !ispinned(pBoard, turn, board, s1, s2))
//		{
//			board[s1.x + 2][s1.y - 1].i.setTexture(ipt);
//
//		}
//		else if (s1.x < 6 && s1.y>0 && ((turn == 0 && board[s1.x + 2][s1.y - 1].t < 0) || (turn == 1 && board[s1.x + 2][s1.y - 1].t > 0)) && !ispinned(pBoard, turn, board, s1, s2))
//		{
//			board[s1.x + 2][s1.y - 1].i.setTexture(ipk);
//
//		}
//
//
//
//		s2.x = s1.x - 2;
//		s2.y = s1.y + 1;
//		if (s1.x > 1 && s1.y < 7 && board[s1.x - 2][s1.y + 1].t == 0 && !ispinned(pBoard, turn, board, s1, s2))
//		{
//			board[s1.x - 2][s1.y + 1].i.setTexture(ipt);
//
//		}
//		else if (s1.x > 1 && s1.y < 7 && ((turn == 0 && board[s1.x - 2][s1.y + 1].t < 0) || (turn == 1 && board[s1.x - 2][s1.y + 1].t > 0)) && !ispinned(pBoard, turn, board, s1, s2))
//		{
//			board[s1.x - 2][s1.y + 1].i.setTexture(ipk);
//
//		}
//
//
//		s2.x = s1.x - 2;
//		s2.y = s1.y - 1;
//		if (s1.x > 1 && s1.y > 0 && board[s1.x - 2][s1.y - 1].t == 0 && !ispinned(pBoard, turn, board, s1, s2))
//		{
//			board[s1.x - 2][s1.y - 1].i.setTexture(ipt);
//
//		}
//		else if (s1.x > 1 && s1.y > 0 && (board[s1.x - 2][s1.y - 1].t != 0) && ((turn == 0 && board[s1.x - 2][s1.y - 1].t < 0) || (turn == 1 && board[s1.x - 2][s1.y - 1].t > 0)) && !ispinned(pBoard, turn, board, s1, s2))
//		{
//			board[s1.x - 2][s1.y - 1].i.setTexture(ipk);
//
//		}
//
//
//		s2.x = s1.x + 1;
//		s2.y = s1.y - 2;
//		if (s1.x < 7 && s1.y>1 && board[s1.x + 1][s1.y - 2].t == 0 && !ispinned(pBoard, turn, board, s1, s2))
//		{
//			board[s1.x + 1][s1.y - 2].i.setTexture(ipt);
//
//		}
//		else if (s1.x < 7 && s1.y>1 && ((turn == 0 && board[s1.x + 1][s1.y - 2].t < 0) || (turn == 1 && board[s1.x + 1][s1.y - 2].t > 0)) && !ispinned(pBoard, turn, board, s1, s2))
//		{
//			board[s1.x + 1][s1.y - 2].i.setTexture(ipk);
//
//		}
//
//		s2.x = s1.x - 1;
//		s2.y = s1.y - 2;
//		if (s1.x > 0 && s1.y > 1 && board[s1.x - 1][s1.y - 2].t == 0 && !ispinned(pBoard, turn, board, s1, s2))
//		{
//			board[s1.x - 1][s1.y - 2].i.setTexture(ipt);
//
//		}
//		else if (s1.x > 0 && s1.y > 1 && (board[s1.x - 1][s1.y - 2].t != 0) && ((turn == 0 && board[s1.x - 1][s1.y - 2].t < 0) || (turn == 1 && board[s1.x - 1][s1.y - 2].t > 0)) && !ispinned(pBoard, turn, board, s1, s2))
//		{
//			board[s1.x - 1][s1.y - 2].i.setTexture(ipk);
//
//		}
//	}
//
//	void move() {
//
//	}
//};
//
//class Rook :public Piece {
//private://to  check for castling
//public:
//	Rook() {}
//	//constructor all types
//	//destructor
//	bool validmove(Vector2i s2, Piece* pBoard[], bool turn, grids board[][8])
//	{
//		if (s2.x >= 0 && s2.y >= 0 && s2.x <= 7 && s2.y <= 7) {
//			return isValidRook(s1, s2, board);
//		}
//		else
//			return 0;
//	}
//	void illuminatepath(Vector2i s1, Texture& ipt, Texture& ipk, Piece* pBoard[], grids board[][8], bool turn)//ipt=illuminate path texture i.e a dot in tranpaernt image, ipk=illuminate path kill
//	{
//		Vector2i s2;
//		bool flag;
//		//rook part
//		flag = 1;
//		for (int i = s1.x + 1; i < 8 && i >= 0 && flag == 1; i++)
//		{
//			s2.x = i;
//			s2.y = s1.y;
//			if (board[i][s1.y].t == 0 && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[i][s1.y].i.setTexture(ipt);
//			}
//			else if (((turn == 0 && board[i][s1.y].t < 0) || (turn == 1 && board[i][s1.y].t > 0)) && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[i][s1.y].i.setTexture(ipk);
//				flag = 0;
//			}
//			else
//			{
//				flag = 0;
//			}
//		}
//		flag = 1;
//		for (int i = s1.x - 1; i < 8 && i >= 0 && flag == 1; i--)
//		{
//
//			s2.x = i;
//			s2.y = s1.y;
//			if (board[i][s1.y].t == 0 && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[i][s1.y].i.setTexture(ipt);
//			}
//			else if (((turn == 0 && board[i][s1.y].t < 0) || (turn == 1 && board[i][s1.y].t > 0)) && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[i][s1.y].i.setTexture(ipk);
//				flag = 0;
//			}
//			else
//			{
//				flag = 0;
//			}
//		}
//		flag = 1;
//		for (int i = s1.y + 1; i < 8 && i >= 0 && flag == 1; i++)
//		{
//
//			s2.x = s1.x;
//			s2.y = i;
//			if (board[s1.x][i].t == 0 && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[s1.x][i].i.setTexture(ipt);
//			}
//			else if (((turn == 0 && board[s1.x][i].t < 0) || (turn == 1 && board[s1.x][i].t > 0)) && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[s1.x][i].i.setTexture(ipk);
//				flag = 0;
//			}
//			else
//			{
//				flag = 0;
//			}
//		}
//
//		flag = 1;
//		for (int i = s1.y - 1; i < 8 && i >= 0 && flag == 1; i--)
//		{
//
//			s2.x = s1.x;
//			s2.y = i;
//			if (board[s1.x][i].t == 0 && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[s1.x][i].i.setTexture(ipt);
//			}
//			else if (((turn == 0 && board[s1.x][i].t < 0) || (turn == 1 && board[s1.x][i].t > 0)) && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[s1.x][i].i.setTexture(ipk);
//				flag = 0;
//			}
//			else
//			{
//				flag = 0;
//			}
//		}
//	}
//
//	void move() {
//
//	}
//};
//
//class Pawn :public Piece {
//private:
//public:
//	Pawn() {
//		movecounter = 0;
//	}
//	Pawn(int r, int c) {
//
//	}
//	//constructor all types
//	//destructor
//
//	bool validmove(Vector2i s2, Piece* pBoard[], bool turn, grids board[][8]) {
//		if (s2.x >= 0 && s2.y >= 0 && s2.x <= 7 && s2.y <= 7) {
//			bool mark = 0;
//			if (type < 0)
//			{
//				if (s2.x == s1.x + 1 && s2.y == s1.y && board[s1.x + 1][s1.y].t == 0)
//				{
//					mark = 1;
//				}
//				if (s2.y == s1.y + 1 && s2.x == s1.x + 1 && board[s1.x + 1][s1.y + 1].t > 0)
//				{
//					mark = 1;
//
//				}
//				if (s2.y == s1.y - 1 && s2.x == s1.x + 1 && board[s1.x + 1][s1.y - 1].t > 0)
//				{
//					mark = 1;
//
//				}
//
//			}
//			if (type > 0)
//			{
//				if (s2.x == s1.x - 1 && s2.y == s1.y && board[s1.x - 1][s1.y].t == 0)
//				{
//					mark = 1;
//
//				}
//				if (s2.y == s1.y + 1 && s2.x == s1.x - 1 && board[s1.x - 1][s1.y + 1].t < 0)
//				{
//					mark = 1;
//
//				}
//				if (s2.y == s1.y - 1 && s2.x == s1.x - 1 && board[s1.x - 1][s1.y - 1].t < 0)
//				{
//					mark = 1;
//
//				}
//
//			}
//
//			if (movecounter == 0)
//			{
//				if (type < 0)
//				{
//					if (s2.x == s1.x + 2 && s2.y == s1.y && board[s1.x + 2][s1.y].t == 0 && board[s1.x + 1][s1.y].t == 0)
//					{
//						mark = 1;
//					}
//
//					//if (s2.y == s1.y + 1 && s2.x == s1.x + 2 && board[s1.x + 2][s1.y + 1].t > 0 &&board[s1.x+1][s1.y+1].t==0)
//					//		{
//					//			mark = 1;
//
//					//		}
//					//if (s2.y == s1.y - 1 && s2.x == s1.x + 2 && board[s1.x + 2][s1.y - 1].t > 0 &&  board[s1.x + 1][s1.y -1].t == 0)
//					//		{
//					//			mark = 1;
//
//					//		}
//				}
//				if (type > 0)
//				{
//					if (s2.x == s1.x - 2 && s2.y == s1.y && board[s1.x - 2][s1.y].t == 0 && board[s1.x - 1][s1.y].t == 0)
//					{
//						mark = 1;
//					}
//					//if (s2.y == s1.y + 1 && s2.x == s1.x - 2 && board[s1.x - 2][s1.y + 1].t < 0 &&  board[s1.x - 1][s1.y + 1].t == 0)
//					//{
//					//	mark = 1;
//
//					//}
//					//if (s2.y == s1.y - 1 && s2.x == s1.x - 2 && board[s1.x - 2][s1.y - 1].t < 0 &&  board[s1.x - 1][s1.y - 1].t == 0)
//					//{
//					//	mark = 1;
//					//}
//
//
//				}
//
//
//
//			}
//
//
//			return mark;
//		}
//		else
//			return 0;
//	}
//
//	void illuminatepath(Vector2i s1, Texture& ipt, Texture& ipk, Piece* pBoard[], grids board[][8], bool turn)//ipt=illuminate path texture i.e a dot in tranpaernt image, ipk=illuminate path kill
//	{
//		Vector2i s2;
//		if (type < 0)
//		{
//			s2.x = s1.x + 1;
//			s2.y = s1.y;
//			if (s1.x < 7 && board[s1.x + 1][s1.y].t == 0 && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[s1.x + 1][s1.y].i.setTexture(ipt);
//			}
//
//
//			s2.x = s1.x + 1;
//			s2.y = s1.y + 1;
//			if (s1.x < 7 && s1.y < 7 && board[s1.x + 1][s1.y + 1].t > 0 && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[s1.x + 1][s1.y + 1].i.setTexture(ipk);
//
//			}
//
//
//			s2.x = s1.x + 1;
//			s2.y = s1.y - 1;
//			if (s1.x < 7 && s1.y>0 && board[s1.x + 1][s1.y - 1].t > 0 && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[s1.x + 1][s1.y - 1].i.setTexture(ipk);
//
//			}
//		}
//		if (type > 0)
//		{
//
//			s2.x = s1.x - 1;
//			s2.y = s1.y;
//			if (s1.x > 0 && board[s1.x - 1][s1.y].t == 0 && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[s1.x - 1][s1.y].i.setTexture(ipt);
//			}
//
//
//			s2.x = s1.x - 1;
//			s2.y = s1.y + 1;
//			if (s1.x > 0 && s1.y < 7 && board[s1.x - 1][s1.y + 1].t < 0 && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[s1.x - 1][s1.y + 1].i.setTexture(ipk);
//
//			}
//
//			s2.x = s1.x - 1;
//			s2.y = s1.y - 1;
//			if (s1.x > 0 && s1.y > 0 && board[s1.x - 1][s1.y - 1].t < 0 && !ispinned(pBoard, turn, board, s1, s2))
//			{
//				board[s1.x - 1][s1.y - 1].i.setTexture(ipk);
//			}
//
//		}
//
//		//if it is the first move of the pawn
//		if (movecounter == 0)
//		{
//			if (type < 0)
//			{
//				s2.x = s1.x + 2;
//				s2.y = s1.y;
//				if (s1.x < 6 && board[s1.x + 2][s1.y].t == 0 && board[s1.x + 1][s1.y].t == 0 && !ispinned(pBoard, turn, board, s1, s2))
//				{
//					board[s1.x + 2][s1.y].i.setTexture(ipt);
//				}
//				//if (s1.x < 6 && s1.y<7&&board[s1.x + 2][s1.y + 1].t > 0 && board[s1.x + 1][s1.y + 1].t == 0)
//				//{
//				//	board[s1.x + 2][s1.y + 1].i.setTexture(ipk);
//
//				//}
//				//if (s1.x < 6 && s1.y >0 && board[s1.x + 2][s1.y - 1].t > 0 && board[s1.x + 1][s1.y - 1].t == 0)
//				//{
//				//	board[s1.x + 2][s1.y - 1].i.setTexture(ipk);
//
//				//}
//			}
//			if (type > 0)
//			{
//
//				s2.x = s1.x - 2;
//				s2.y = s1.y;
//				if (s1.x > 1 && board[s1.x - 2][s1.y].t == 0 && board[s1.x - 1][s1.y].t == 0 && !ispinned(pBoard, turn, board, s1, s2))
//				{
//					board[s1.x - 2][s1.y].i.setTexture(ipt);
//				}
//				//if (s1.x > 1 && s1.y<7&&board[s1.x - 2][s1.y + 1].t < 0 && board[s1.x - 1][s1.y].t == 0)
//				//{
//				//	board[s1.x - 2][s1.y + 1].i.setTexture(ipk);
//
//				//}
//				//if (s1.x > 1 && s1.y >0 && board[s1.x - 2][s1.y - 1].t < 0 && board[s1.x - 1][s1.y].t == 0)
//				//{
//				//	board[s1.x - 2][s1.y - 1].i.setTexture(ipk);
//				//}
//
//			}
//
//
//
//		}
//	}
//
//	void move() {
//
//	}
//};
//void illuminatepathchecker(Vector2i s1, Piece* pBoard[], grids board[][8], bool turn, Player p1, Player p2, Texture& ipt, Texture& ipk)
//{
//
//
//	for (int i = 0; i < 32; i++)
//	{
//		//yahan x aur y ka msla ho skta ha ani x ki jagah y 
//		//ye check kre ga k kis piece ka illuminate path nikalna ha
//		if (s1.x == pBoard[i]->getpos().x && s1.y == pBoard[i]->getpos().y)
//		{
//
//			pBoard[i]->illuminatepath(s1, ipt, ipk, pBoard, board, turn);
//		}
//	}
//
//}
//void print2d(grids a[8][8])
//{
//	for (int i = 0; i < 8; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//			std::cout << a[i][j].t;
//			if (i == 0 || i == 1)
//			{
//				cout << " ";
//			}
//			else
//			{
//				cout << "  ";
//			}
//		}
//		std::cout << endl;
//	}
//}
//Vector2i convert(Vector2f s1)
//{
//	int y = s1.x - i_offset / tsx;
//	int x = s1.y - j_offset / tsy;
//	Vector2i s2(x, y);
//	return s2;
//}
//Vector2i convert(Vector2i s1)
//{
//	int y = (s1.x - i_offset) / tsx;
//	int x = (s1.y - j_offset) / tsy;
//	Vector2i s2(x, y);
//	return s2;
//}
//
//
////bool diagonal(grids board[][8], Vector2i s1, Vector2i s2)
////{
////	bool flag = 1;
////	if (s1.x >= 0 && s1.y >= 0 && s1.x <= 7 && s1.y <= 7) {
////		if (s2.x - s1.x == s1.y - s2.y) {
////			if (s2.x - s1.x > 0) {
////				for (int i = s1.x, j = s1.y; i > s2.x && j < s1.y; i--, j++)
////				{
////					if (board[i][j].t != 0)
////					{
////						flag = 0;
////					}
////				}
////			}
////			else if (s2.x - s1.x < 0) {
////				for (int i = s1.x, j = s1.y; i < s2.x && j > s1.y; i++, j--)
////				{
////					if (board[i][j].t != 0)
////					{
////						flag = 0;
////					}
////				}
////			}
////		}
////			else if (s2.x - s1.x == -(s2.y - s1.y)) {
////				if (s2.x - s1.x < 0) {
////					for (int i = s1.x, j = s1.y; i > s2.x && j > s2.y; i--, j--)
////					{
////						if (board[i][j].t != 0)
////						{
////							flag = 0;
////						}
////					}
////				}
////				else if (s2.x - s1.x > 0) {
////					for (int i = s1.x, j = s1.y; i < s2.x && j < s2.y; i++, j++)
////					{
////						if (board[i][j].t != 0)
////						{
////							flag = 0;
////						}
////					}
////				}
////			}
////			else
////			{
////				flag = 0;
////			}
////
////		
////	}
////	else
////	{
////		flag = 0;
////	}
////
////	return flag;
////}
//void setTypeandAssignObjects(Piece* a[], grids board[8][8]) {
//
//	// filling the grid
//	for (int i = 0; i < 8; i++)
//	{
//		int sum = 5;
//		int sum2 = -5;
//		for (int j = 0; j < 8; j++)
//		{
//			if (i == 0)
//			{
//				if (j < 4)
//					board[i][j].t = sum2++;
//				else if (j == 4)
//				{
//					board[i][j].t = sum2;
//					sum2--;
//				}
//				else {
//					board[i][j].t = --sum2;
//				}
//			}
//			if (i == 1)
//			{
//				board[i][j].t = -6;
//			}
//			if (i > 1 && i < 6)
//			{
//				board[i][j].t = 0;
//			}
//			if (i == 6)
//			{
//				board[i][j].t = 6;
//			}
//			if (i == 7)
//			{
//				if (j < 4)
//					board[i][j].t = sum--;
//				else if (j == 4)
//				{
//					board[i][j].t = sum;
//					sum++;
//				}
//				else {
//					board[i][j].t = ++sum;
//				}
//			}
//		}
//	}
//
//
//	//creating dynamic objects
//
//	int count = 0;
//
//	for (int i = 0; i < 8; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//			if (i == 0 || i == 1 || i == 6 || i == 7)
//			{
//				switch (abs(board[i][j].t))
//				{
//				case 1:
//					a[count] = new King;
//					break;
//				case 2:
//					a[count] = new Queen;
//					break;
//				case 3:
//					a[count] = new Bishop;
//					break;
//				case 4:
//					a[count] = new Knight;
//					break;
//				case 5:
//					a[count] = new Rook;
//					break;
//				case 6:
//					a[count] = new Pawn;
//					break;
//				default:
//					break;
//				}
//				(*a[count]).setpiece(i, j, board[i][j].t);
//
//				count++;
//			}
//		}
//	}
//}
//
//
//void SetTextureA(grids board[8][8], Texture& whiteknight, Texture& blackknight, Texture& whitequeen, Texture& blackqueen, Texture& whiteking, Texture& blackking, Texture& whitebishop, Texture& blackbishop, Texture& whiterook, Texture& blackrook, Texture& whitepawn, Texture& blackpawn, Texture& ipt, Texture& ipk)
//{
//	for (int i = 0; i < 8; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//
//			if (board[i][j].t == 1)
//			{
//				sf::Vector2u textureSize = whiteking.getSize();
//				float scaleX = tsx / static_cast<float>(textureSize.x);
//				float scaleY = tsy / static_cast<float>(textureSize.y);
//				board[i][j].s.setScale(scaleX, scaleY);
//				board[i][j].s.setTexture(whiteking);
//
//			}
//			if (board[i][j].t == 2)
//			{
//				sf::Vector2u textureSize = whitequeen.getSize();
//				float scaleX = tsx / static_cast<float>(textureSize.x);
//				float scaleY = tsy / static_cast<float>(textureSize.y);
//				board[i][j].s.setScale(scaleX, scaleY);
//				board[i][j].s.setTexture(whitequeen);
//
//			}
//			if (board[i][j].t == 3)
//			{
//				sf::Vector2u textureSize = whitebishop.getSize();
//				float scaleX = tsx / static_cast<float>(textureSize.x);
//				float scaleY = tsy / static_cast<float>(textureSize.y);
//				board[i][j].s.setScale(scaleX, scaleY);
//				board[i][j].s.setTexture(whitebishop);
//
//			}
//			if (board[i][j].t == 4)
//			{
//				sf::Vector2u textureSize = whiteknight.getSize();
//				float scaleX = tsx / static_cast<float>(textureSize.x);
//				float scaleY = tsy / static_cast<float>(textureSize.y);
//				board[i][j].s.setScale(scaleX, scaleY);
//				board[i][j].s.setTexture(whiteknight);
//
//			}
//			if (board[i][j].t == 5)
//			{
//				sf::Vector2u textureSize = whiterook.getSize();
//				float scaleX = tsx / static_cast<float>(textureSize.x);
//				float scaleY = tsy / static_cast<float>(textureSize.y);
//				board[i][j].s.setScale(scaleX, scaleY);
//				board[i][j].s.setTexture(whiterook);
//
//			}
//			if (board[i][j].t == 6)
//			{
//				sf::Vector2u textureSize = whitepawn.getSize();
//				float scaleX = tsx / static_cast<float>(textureSize.x);
//				float scaleY = tsy / static_cast<float>(textureSize.y);
//				board[i][j].s.setScale(scaleX, scaleY);
//				board[i][j].s.setTexture(whitepawn);
//
//			}
//
//
//			if (board[i][j].t == -1)
//			{
//				sf::Vector2u textureSize = blackking.getSize();
//				float scaleX = tsx / static_cast<float>(textureSize.x);
//				float scaleY = tsy / static_cast<float>(textureSize.y);
//				board[i][j].s.setScale(scaleX, scaleY);
//				board[i][j].s.setTexture(blackking);
//
//			}
//			if (board[i][j].t == -2)
//			{
//				sf::Vector2u textureSize = blackqueen.getSize();
//				float scaleX = tsx / static_cast<float>(textureSize.x);
//				float scaleY = tsy / static_cast<float>(textureSize.y);
//				board[i][j].s.setScale(scaleX, scaleY);
//				board[i][j].s.setTexture(blackqueen);
//
//			}
//			if (board[i][j].t == -3)
//			{
//				sf::Vector2u textureSize = blackbishop.getSize();
//				float scaleX = tsx / static_cast<float>(textureSize.x);
//				float scaleY = tsy / static_cast<float>(textureSize.y);
//				board[i][j].s.setScale(scaleX, scaleY);
//				board[i][j].s.setTexture(blackbishop);
//
//			}
//			if (board[i][j].t == -4)
//			{
//				sf::Vector2u textureSize = blackknight.getSize();
//				float scaleX = tsx / static_cast<float>(textureSize.x);
//				float scaleY = tsy / static_cast<float>(textureSize.y);
//				board[i][j].s.setScale(scaleX, scaleY);
//				board[i][j].s.setTexture(blackknight);
//
//			}
//			if (board[i][j].t == -5)
//			{
//				sf::Vector2u textureSize = blackrook.getSize();
//				float scaleX = tsx / static_cast<float>(textureSize.x);
//				float scaleY = tsy / static_cast<float>(textureSize.y);
//				board[i][j].s.setScale(scaleX, scaleY);
//				board[i][j].s.setTexture(blackrook);
//
//			}
//			if (board[i][j].t == -6)
//			{
//				sf::Vector2u textureSize = blackpawn.getSize();
//				float scaleX = tsx / static_cast<float>(textureSize.x);
//				float scaleY = tsy / static_cast<float>(textureSize.y);
//				board[i][j].s.setScale(scaleX, scaleY);
//				board[i][j].s.setTexture(blackpawn);
//			}
//			sf::Vector2u textureSize = ipk.getSize();
//			sf::Vector2u text = ipt.getSize();
//			float x, y;
//			x = (textureSize.x + text.x) / 2.0;
//			y = (textureSize.y + text.y) / 2.0;
//
//			float scaleX = (tsx) / static_cast<float>(x);
//			float scaleY = (tsy) / static_cast<float>(y);
//			board[i][j].i.setScale(scaleX, scaleY);
//
//		}
//	}
//}
//void setPositionA(grids board[8][8], Piece* pBoard[])
//{
//	Texture texture;
//	for (int i = 0; i < 32; i++)
//	{
//		Vector2i s1 = pBoard[i]->getpos();
//		int x = pBoard[i]->gettype();
//		board[s1.x][s1.y].s.setPosition(i_offset + tsx * s1.y, j_offset + tsy * s1.x);
//	}
//	for (int i = 2; i < 6; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//			board[i][j].s.setTexture(texture);
//			board[i][j].s.setPosition(i_offset + tsx * j, j_offset + tsy * i);
//		}
//	}
//	for (int i = 0; i < 8; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//			//	board[i][j].i.setTexture(texture);
//			board[i][j].i.setPosition(i_offset + (tsx + 2) * j, j_offset + tsy * i);
//		}
//	}
//
//}
//
//void swapsprite(Vector2i& s1, Vector2i& s2, grids board[][8]) {
//	swap(board[s1.x][s1.y].t, board[s2.x][s2.y].t);
//	swap(board[s1.x][s1.y].s, board[s2.x][s2.y].s);
//}
//
//void refresh(grids board[][8], RenderWindow& window, RectangleShape& a, RectangleShape& b,RectangleShape& c,Text& d,Text& e,Text& f)
//{
//	window.clear();
//	window.draw(a);
//	window.draw(b);
//	window.setFramerateLimit(1000);
//	for (int i = 0; i < 8; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//			window.draw(board[i][j].s);
//			window.draw(board[i][j].i);
//		}
//	}
//	window.draw(c);
//	window.draw(d);
//	window.draw(e);
//	window.draw(f);
//	
//	window.display();
//	window.setFramerateLimit(100);
//
//}
//void refresh2(grids board[][8], RenderWindow& window, RectangleShape& a, RectangleShape& b,Sprite& p, RectangleShape& c, Text& d, Text& e, Text& f)
//{
//	window.clear();
//	window.draw(a);
//	window.draw(b);
//	window.draw(p);
//	window.setFramerateLimit(60);
//	for (int i = 0; i < 8; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//			window.draw(board[i][j].s);
//			window.draw(board[i][j].i);
//		}
//	}
//	window.draw(c);
//	window.draw(d);
//	window.draw(e);
//	window.draw(f);
//	window.display();
//	window.setFramerateLimit(1000);
//
//}
//void takeanimation(grids board[][8], Piece* pBoard[], Vector2i& s1, Vector2i& s2, RenderWindow& window, RectangleShape& a, RectangleShape& b,RectangleShape& c, Text& d, Text& e, Text& f) {
//
//	Vector2f temp = board[s1.x][s1.y].s.getPosition();
//	Vector2f temp1 = board[s1.x][s1.y].s.getPosition();
//	Vector2f temp2 = board[s2.x][s2.y].s.getPosition();
//	float dx = (temp2.x - temp.x) * 0.04;
//	float dy = (temp2.y - temp.y) * 0.04;
//	Vector2f move1(dx, dy);
//	while (std::abs(temp.x - temp2.x) > 0.01 || std::abs(temp.y - temp2.y) > 0.01) {
//		temp.x = temp.x + move1.x;
//		temp.y = temp.y + move1.y;
//		board[s1.x][s1.y].s.move(dx, dy);
//		refresh(board, window, a, b,c,d,e,f);
//	}
//	for (int i = 0; i < 32; i++)
//	{
//
//		if (pBoard[i]->getpos() == s2)
//		{
//			Vector2i newp=Vector2i(-99, -99);
//			pBoard[i]->setpos(newp);
//			pBoard[i]->settype(0);
//		}
//		if (pBoard[i]->getpos() == s1)
//		{
//			pBoard[i]->setpos(s2);
//		}
//	}
//	board[s1.x][s1.y].s.setPosition(temp2.x, temp2.y);
//	board[s2.x][s2.y].s.setColor(Color::Transparent);
//	board[s2.x][s2.y].s.setPosition(temp1.x, temp1.y);
//	board[s2.x][s2.y].t = 0;
//	swapsprite(s1, s2, board);
//	refresh(board, window, a, b, c, d, e, f);
//}
//
//
//void moveanimation(grids board[][8], Piece* pBoard[], Vector2i& s1, Vector2i& s2, RenderWindow& window, RectangleShape& a, RectangleShape& b, RectangleShape& c, Text& d, Text& e, Text& f) {
//
//	Vector2f temp = board[s1.x][s1.y].s.getPosition();
//	Vector2f temp1 = board[s1.x][s1.y].s.getPosition();
//	Vector2f temp2 = board[s2.x][s2.y].s.getPosition();
//	float dx = (temp2.x - temp.x) * 0.04;
//	float dy = (temp2.y - temp.y) * 0.04;
//	Vector2f move1(dx, dy);
//	while (std::abs(temp.x - temp2.x) > 0.01 || std::abs(temp.y - temp2.y) > 0.01) {
//		temp.x = temp.x+move1.x;
//		temp.y= temp.y+move1.y;
//		board[s1.x][s1.y].s.move(dx, dy);
//		refresh(board, window, a, b, c, d, e, f);
//	}
//	for (int i = 0; i < 32; i++)
//	{
//		if (pBoard[i]->getpos() == s1)
//		{
//			pBoard[i]->setpos(s2);
//		}
//	}
//	board[s1.x][s1.y].s.setPosition(temp2.x, temp2.y);
//	board[s2.x][s2.y].s.setPosition(temp1.x, temp1.y);
//	swapsprite(s1, s2, board);
//	refresh(board, window, a, b, c, d, e, f);
//}
//
//void printpBoard(Piece*pBoard[]) {
//	for (int i = 0; i < 32; i++)
//	{
//		cout << pBoard[i]->gettype()<<":  ";
//		cout << pBoard[i]->getpos().x << " " << pBoard[i]->getpos().y << endl;
//	}
//}
//	bool searchandreturnvalidmove(Vector2i s1, Vector2i s2, grids board[][8], Piece * pBoard[], bool turn) {
//
//		Vector2i KingPos = getkingpos(pBoard, turn);
//		Vector2i ogp = s1;
//		Vector2i ex(-99, -99);
//		for (int i = 0; i < 32; i++) {
//			if (pBoard[i]->getpos() == s1)
//			{
//				if (pBoard[i]->validmove(s2, pBoard, turn, board) && incheck(KingPos, pBoard, turn,board))
//				{
//					int x = pBoard[i]->gettype();
//					int f = findit(pBoard, s2);
//					pBoard[i]->setpos(s2);
//					int y = 0;
//					if (f != -1) {
//						y = pBoard[f]->gettype();
//						pBoard[f]->settype(0);
//						pBoard[f]->setpos(ex);
//					}
//					board[s2.x][s2.y].t = x;
//					board[s1.x][s1.y].t = 0;
//					KingPos = getkingpos(pBoard, turn);
//					print2d(board);
//					printpBoard(pBoard);
//					if (!incheck(KingPos, pBoard, turn,board)) {
//						if (f != -1) {
//							pBoard[f]->setpos(s2);
//							pBoard[f]->settype(y);
//						}
//						pBoard[i]->setpos(s1);
//						board[s2.x][s2.y].t = y;
//						board[s1.x][s1.y].t = x;
//						return true;
//					}
//					if (f != -1) {
//						pBoard[f]->setpos(s2);
//						pBoard[f]->settype(y);
//					}
//					pBoard[i]->setpos(s1);
//					board[s2.x][s2.y].t = y;
//					board[s1.x][s1.y].t = x;
//
//				}
//				else if (pBoard[i]->validmove(s2, pBoard, turn, board) && !incheck(KingPos, pBoard, turn, board))
//				{
//					int x = pBoard[i]->gettype();
//					int f = findit(pBoard, s2);
//					pBoard[i]->setpos(s2);
//					int y = 0;
//					if (f != -1) {
//						y = pBoard[f]->gettype();
//						pBoard[f]->settype(0);
//						pBoard[f]->setpos(ex);
//					}
//					board[s2.x][s2.y].t = x;
//					board[s1.x][s1.y].t = 0;
//					KingPos = getkingpos(pBoard, turn);
//					print2d(board);
//					printpBoard(pBoard);
//					if (!incheck(KingPos, pBoard, turn, board)) {
//						if (f != -1) {
//							pBoard[f]->setpos(s2);
//							pBoard[f]->settype(y);
//						}
//						pBoard[i]->setpos(s1);
//						board[s2.x][s2.y].t = y;
//						board[s1.x][s1.y].t = x;
//						return true;
//					}
//					if (f != -1) {
//						pBoard[f]->setpos(s2);
//						pBoard[f]->settype(y);
//					}
//					pBoard[i]->setpos(s1);
//					board[s2.x][s2.y].t = y;
//					board[s1.x][s1.y].t = x;
//
//				}
//				else {
//					return(pBoard[i]->validmove(s2,pBoard,turn,board) && !incheck(KingPos, pBoard, turn,board));
//				}
//			}
//		}
//		return 0;
//	}
//
//
//	bool ischeckmate(Piece* pBoard[], bool turn, grids board[8][8]) {
//
//		bool flag = 1;
//		if (incheck(getkingpos(pBoard, turn), pBoard, turn, board)) {
//
//
//			Vector2i s1(0, 0);
//			for (int k = 0; k < 32; k++)
//			{
//				if (turn == 0 && pBoard[k]->gettype() >= 1) {
//					s1 = pBoard[k]->getpos();
//					for (int i = 0; i < 8; i++)
//					{
//						for (int j = 0; j < 8; j++)
//						{
//							Vector2i s2(i, j);
//							if (findit(pBoard, s2) == -1 || pBoard[findit(pBoard, s2)]->gettype() < 1) {
//								if (searchandreturnvalidmove(s1, s2, board, pBoard, turn)) {
//									cout << "NOT CHECKMATE BECAUSE Piece" << k << "  at location" << s2.x << " " << s2.y << endl;
//									cout << 123456 << endl;;
//									flag=0;
//								}
//							}
//						}
//					}
//				}
//
//				if (turn == 1 && pBoard[k]->gettype() <= -1) {
//					s1 = pBoard[k]->getpos();
//					for (int i = 0; i < 8; i++)
//					{
//						for (int j = 0; j < 8; j++)
//						{
//							Vector2i s2(i, j);
//
//							if (findit(pBoard, s2) == -1 || pBoard[findit(pBoard, s2)]->gettype() > -1) {
//								if (searchandreturnvalidmove(s1, s2, board, pBoard, turn)) {
//									cout << 123456 << endl;
//									cout << "NOT CHECKMATE BECAUSE Piece" << k << "  at location" << s2.x << " " << s2.y << endl;
//									flag = 0;
//								}
//							}
//						}
//					}
//				}
//			}
//			if(flag==1)
//			cout << "checkmate" << endl;
//			return flag;
//		}
//		else {
//			return false;
//		}
//	}
//	bool isstalemate(Piece* pBoard[], bool turn, grids board[8][8]) {
//
//		bool flag = 1;
//		if (!incheck(getkingpos(pBoard, turn), pBoard, turn, board)) {
//
//
//			Vector2i s1(0, 0);
//			for (int k = 0; k < 32; k++)
//			{
//				if (turn == 0 && pBoard[k]->gettype() >= 1) {
//					s1 = pBoard[k]->getpos();
//					for (int i = 0; i < 8; i++)
//					{
//						for (int j = 0; j < 8; j++)
//						{
//							Vector2i s2(i, j);
//							if (findit(pBoard, s2) == -1 || pBoard[findit(pBoard, s2)]->gettype() < 1) {
//								if (searchandreturnvalidmove(s1, s2, board, pBoard, turn)) {
//									cout << "NOT STALEMATE BECAUSE Piece" << k << "  at location" << s2.x << " " << s2.y << endl;
//									cout << 123456 << endl;;
//									flag = 0;
//								}
//							}
//						}
//					}
//				}
//
//				if (turn == 1 && pBoard[k]->gettype() <= -1) {
//					s1 = pBoard[k]->getpos();
//					for (int i = 0; i < 8; i++)
//					{
//						for (int j = 0; j < 8; j++)
//						{
//							Vector2i s2(i, j);
//
//							if (findit(pBoard, s2) == -1 || pBoard[findit(pBoard, s2)]->gettype() > -1) {
//								if (searchandreturnvalidmove(s1, s2, board, pBoard, turn)) {
//									cout << 123456 << endl;
//									cout << "NOT STALEMATE BECAUSE Piece" << k << "  at location" << s2.x << " " << s2.y << endl;
//									flag = 0;
//								}
//							}
//						}
//					}
//				}
//			}
//			if (flag == 1)
//				cout << "Stalemate" << endl;
//			return flag;
//		}
//		else {
//			return false;
//		}
//	}
