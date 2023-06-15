//Kelompok 6 - IF A 2021

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
using namespace sf;

//inisialisasi variabel
const double screenLebar = 800;
const double screenTinggi = 600;
const int batasKiri = 150;
const int batasKanan = 640;
const int userLebar = 60;
const int userTinggi = 90;
string scoreGame = "";
string namaKelompok = "";
string penutup = "";
int score = 0;
char str[10];
double gameSpeed = 0.1;

//Membuat Window Game
RenderWindow app(VideoMode(screenLebar, screenTinggi), "KELOMPOK 6 IF A - AGAINST THE CURRENT");

//Fungsi parameter untuk mendapat random number
int getRandomNumber(int x, int y);

//Fungsi paramater game over
int gameOver();

//Fungsi parameter main game
int mainGame();

int main()
{
	//Inisialisasi dan load file background dalam intro game
	Texture backStart, logo;
	
	//Load gambar yang diperlukan dalam fungsi main
	if(!backStart.loadFromFile("images/start.png")){
		return EXIT_FAILURE;	
	}
	if(!logo.loadFromFile("images/uns.png")){
		return EXIT_FAILURE;
	}
	
	Sprite BackStart(backStart), Logo(logo);
	
    //Inisialisasi musik dalam intro game
	SoundBuffer soundStart;
    soundStart.loadFromFile("sounds/start.wav");
    Sound SoundStart;
    SoundStart.setBuffer(soundStart);
    SoundStart.play();
    
    //Melakukan looping intro game
    while (app.isOpen())
    {
    	Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed){
                app.close();
        	}
			if(event.type == Event::KeyPressed)
            {
                if(event.key.code == Keyboard::Space)
                {
					mainGame();
				}
        	}
    	}
        
        //Inisialisasi teks font dalam intro game
        Font fontStart;
        fontStart.loadFromFile("fonts/nue.ttf");
        
		namaKelompok = "M0518015 - Farhan Sungkar\n"
					   "M0521013 - Asyahra Rahmasari Ariyahaq\n"
					   "M0521018 - Diana Adilla Lubis\n"
					   "M0521026 - Hafidh Muhammad Akbar\n";
        
		Text textnama(namaKelompok, fontStart, 23);
        textnama.setPosition(15, 480);
        Logo.setPosition(0, 0);
        
        //Redraw posisi
    	app.clear();
        app.draw(BackStart);
        app.draw(Logo);
        app.draw(textnama);
        app.display();
	}
}

//Fungsi main game
int mainGame()
{	
    //Inisialisasi music main game
    SoundBuffer soundGame;
    soundGame.loadFromFile("sounds/game.wav");
    Sound SoundGame;
    SoundGame.setBuffer(soundGame);

    Texture backGame, user, car1, car2, car3, car4, logo;
    
	//Inisialisasi font dalam main game
    Font fontMain;
    fontMain.loadFromFile("fonts/gameplay.ttf");

    //Load semua gambar yang diperlukan di main game
    if(!backGame.loadFromFile("images/back.png")){
    	return EXIT_FAILURE;	
	}
    if(!logo.loadFromFile("images/uns.png")){
    	return EXIT_FAILURE;
	}
    if(!user.loadFromFile("images/user.png")){
    	return EXIT_FAILURE;
	}
    if(!car1.loadFromFile("images/car1.png")){
    	return EXIT_FAILURE;
	}
    if(!car2.loadFromFile("images/car2.png")){
    	return EXIT_FAILURE;
	}
    if(!car3.loadFromFile("images/car3.png")){
    	return EXIT_FAILURE;
	}
    if(!car4.loadFromFile("images/car4.png")){
    	return EXIT_FAILURE;
	}

    //Membuat sprite dari gambar
    Sprite BackGame(backGame), BackGame1(backGame), Logo(logo), User(user), Car1(car1), Car2(car2), Car3(car3), Car4(car4);

    double UserX, UserY, Car1X, Car1Y, Car2X, Car2Y, Car3X, Car3Y, Car4X, Car4Y;

    //Mengatur posisi awal user dan rintangan(car)
	UserX = screenLebar / 2;
	UserY = screenTinggi - userTinggi;
	Car1X = getRandomNumber(batasKiri, batasKanan);
	Car2X = getRandomNumber(batasKiri, batasKanan);
	Car3X = getRandomNumber(batasKiri, batasKanan);
	Car4X = getRandomNumber(batasKiri, batasKanan);
    Car1Y = 0, Car2Y = -140, Car3Y = -280, Car4Y = -420;
    double BackGameY1 = 0;
    double BackGameY2 = -600;

	//Memutar lagu main game
    SoundGame.play();
    SoundGame.setLoop(true);

    //Melakukan looping main game
    while (app.isOpen())
    {
        //Inisialisasi string score dalam main game
        scoreGame = "SCORE: ";
        Text textscore(scoreGame, fontMain, 15);
        textscore.setPosition(5, 5);
        
        sprintf(str, "%d", score); //mengubah int ke string
        Text textscore1(str, fontMain, 15);
        textscore1.setPosition(75, 5);
        
        Logo.setPosition(670, 0);

        //mengatur posisi awal user dan rintangan(car)
        User.setPosition(UserX, UserY);
        Car1.setPosition(Car1X, Car1Y);
        Car2.setPosition(Car2X, Car2Y);
        Car3.setPosition(Car3X, Car3Y);
        Car4.setPosition(Car4X, Car4Y);

        //Membuat background bergerak (scroll)
        BackGame.setPosition(0, BackGameY1);
        BackGame1.setPosition(0, BackGameY2);
        if (BackGameY2 > 0){
            BackGameY1 = 0;
            BackGameY2 = BackGameY1 - 500;
        }
        BackGameY1 += 0.1;
        BackGameY2 += 0.1;

        //Mengatur loop untuk rintangan(car)
        if(Car1Y > screenTinggi){
			Car1Y = 0; 
			Car1X = getRandomNumber(batasKiri, batasKanan);
			score++;
		}
		else{
			Car1Y += gameSpeed;
		}
        
		if(Car2Y > screenTinggi){
			Car2Y = 0;
			Car2X = getRandomNumber(batasKiri, batasKanan);
			score++;
		}
		else{
			Car2Y += gameSpeed;
		}
        
		if(Car3Y > screenTinggi){
			Car3Y = 0;
			Car3X = getRandomNumber(batasKiri, batasKanan);
			score++;
		}
		else{
			Car3Y += gameSpeed;
		}
        
		if(Car4Y > screenTinggi){
			Car4Y = 0;
			Car4X = getRandomNumber(batasKiri, batasKanan);
			score++;
		}
		else{
			Car4Y += gameSpeed;
		}

        //Mengatur game level agar semakin tinggi score semkain sulit
        if(score > 10 && score < 15){
			gameSpeed = 0.2;
		}
        if(score >= 15 && score < 20){
			gameSpeed = 0.3;
		}
        if(score >= 20 && score < 30){
			gameSpeed = 0.4;
		}
		if(score >= 30 && score < 35){
			gameSpeed = 0.5;
		}
        if(score >= 35){
			gameSpeed = 0.6;
		}

        //Membuat agar dapat menerima inputan dari keyboard
        Event event;
        while(app.pollEvent(event))
        {
            if(event.type == Event::Closed){
                app.close();
			}
			
            if(event.type == Event::KeyPressed){
                if(event.key.code == Keyboard::Left){
					if(UserX > batasKiri){
						UserX -= 10;
					}
				}
                if(event.key.code == Keyboard::Right){
					if(UserX < batasKanan){
						UserX += 10;
					}
				}
                if(event.key.code == Keyboard::Up){
					if(UserY > 0){
						UserY -= 10;
					}
				}
                if(event.key.code == Keyboard::Down){
					if(UserY < screenTinggi - 70){
						UserY += 10;
					}
				}
            }
        }

        //Pengecekan jika user terkena rintangan(car)
        if(((UserX >= (Car1X - 40)) && (UserX <= (Car1X + 40))) && ((UserY >= (Car1Y - 40)) && (UserY) <= (Car1Y + 40))){
            SoundGame.stop();
			gameOver();
    	}
    	
        if (((UserX >= (Car2X - 40)) && (UserX <= (Car2X + 40))) && ((UserY >= (Car2Y - 40)) && (UserY) <= (Car2Y + 40))){
        	SoundGame.stop();
			gameOver();
        }
            
        if (((UserX >= (Car3X - 40)) && (UserX <= (Car3X + 40))) && ((UserY >= (Car3Y - 40)) && (UserY) <= (Car3Y + 40))){
            SoundGame.stop();
			gameOver();
        }
        
        if (((UserX >= (Car4X - 50)) && (UserX <= (Car4X + 50))) && ((UserY >= (Car4Y - 50)) && (UserY) <= (Car4Y + 50))){
            SoundGame.stop();
			gameOver();
        }

        //Redraw posisi
        app.clear();
        app.draw(BackGame);
        app.draw(BackGame1);
        app.draw(Logo);
        app.draw(User);
        app.draw(Car1);
        app.draw(Car2);
        app.draw(Car3);
        app.draw(Car4);
        app.draw(textscore);
        app.draw(textscore1);
        app.display();
    }
    return EXIT_SUCCESS;
}

//Fungsi Game Over
int gameOver()
{
	//Inisialisasi dan load file background game over
    Texture backOver, logo, meme;
    if(!backOver.loadFromFile("images/end.png")){
    	return EXIT_FAILURE;
	}
    if(!meme.loadFromFile("images/meme.png")){
    	return EXIT_FAILURE;
	}
    if(!logo.loadFromFile("images/uns.png")){
    	return EXIT_FAILURE;
	}
	
    Sprite BackOver(backOver), Logo(logo), Meme(meme);
    
	//Inisialisasi musik dalam game over
	SoundBuffer soundOver;
    soundOver.loadFromFile("sounds/end.wav");
    Sound SoundOver;
    SoundOver.setBuffer(soundOver);
	SoundOver.play();
    
	//Melakukan looping game over
	while (app.isOpen())
    {
        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed){
                app.close();
        	}
        	if(event.type == Event::KeyPressed){
                if(event.key.code == Keyboard::Space){
					//Restart score dan gamespeed agar ketika play again ter-restart
					score = 0;
					gameSpeed = 0.1;
					mainGame();
				}
                if(event.key.code == Keyboard::Escape){
					app.close();
				}
        	}
    	}
        
        //Inisialisasi teks font dalam game over
		Font fontOver;
        fontOver.loadFromFile("fonts/gameplay.ttf");
        Font fontPenutup;
        fontPenutup.loadFromFile("fonts/nue.ttf");
        
		scoreGame = "YOUR SCORE: ";
        Text textscore(scoreGame, fontOver, 40);
        textscore.setPosition(230, 450);
        
		sprintf(str, "%d", score);
        Text textscore1(str, fontOver, 40);
        textscore1.setPosition(540, 450);
        
        penutup = "Thank you for playing this game\n"
					 "\t\tHope you enjoy this game!";
		
		Text textpenutup(penutup, fontPenutup, 20);
        textpenutup.setPosition(280, 520);
        
        Meme.setPosition(20, 400);
    	Logo.setPosition(670, 0);
        
        //Redraw posisi
        app.clear();
        app.draw(BackOver);
        app.draw(Logo);
        app.draw(textscore);
        app.draw(textscore1);
        app.draw(textpenutup);
        app.draw(Meme);
        app.display();

    }
}

int getRandomNumber(int x, int y)
{
    static bool first = true;
	if(first){
		srand(time(NULL));
		first = false;
	}
    int hasil = x + rand() % (y - x);
    
	return hasil;
}
