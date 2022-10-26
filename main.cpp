// FILE: Project#3.cpp
// AUTHOR: Carmel Laurentia
// DATE: 5/31/2022
//
// ABOUT: practice the use json, curl, and vector

#include <iostream>
#include <vector>
#include "quiz.hpp"

using std::cout;
using std:: endl;

int main() {

	cout << "    --- Welcome to Trivia Moment --- " << endl;
	cout << "You'll be presented 10 questions with choices. Choose " << endl;
	cout << "the correct answer and win a surprise. Good Luck! \n" << endl;
	
	string repeat = "no";
	
	do {
		system("curl https://opentdb.com/api.php?amount=10 > quiz.data");

		cout << endl;

		Quiz *q = new Quiz("quiz.data");
  
 		int score = q->print_all_questions();

		cout << "You got " << score << "/10 correct" << endl;
		
		if (score >= 0 && score <= 3) {
			cout << "Come back later, lil kitty waiting ฅ^•ﻌ•^ฅ \n"<< endl;
		} else if (score > 3 && score <= 5) {
			cout << "Fair enough, a lil porcupine for you (•ᴥ• )́`́'́`́'́⻍\n"<< endl;
		} else if (score > 5 && score <=8) {
			cout << "Good job! Happy lil bunny for you U(⁎˃ᆺ˂)U\n"<< endl;
		} else {
			cout << "Excellent! Here is a bear hug ʕっ•ᴥ•ʔっ\n"<< endl;
		}

		cout << "Would you like to play again? (yes/no) > ";
		std::cin >> repeat;
		cout << "\n" << endl;

		delete q;
	
	} while (repeat == "yes");
	
}

/* SAMPLE OUTPUT
    --- Welcome to Trivia Moment --- 
You'll be presented 10 questions with choices. Choose 
the correct answer and win a surprise. Good Luck! 

  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
  0     0    0     0    0     0      0      0 --:--:-- --:--:-- --:--:--      0     0    0     0    0     0      0      0 --:--:-- --:--:-- --:--:--    100  2660    0  2660    0     0  10555      0 --:--:-- --:--:-- --:--:-- 10513

Category: Entertainment: Film
Type: multiple
Difficulty: hard
Question: In the 1976 film &#039;Taxi Driver&#039;, how many guns did Travis buy from the salesman?
    1) 4
    2) 6
    3) 2
    4) 1
        Which number to choose? > 2
            Incorrect! The answer is 4

Category: Politics
Type: multiple
Difficulty: medium
Question: Before 2011, &quot;True Capitalist Radio&quot; was known by a different name. What was that name?
    1) True Conservative Radio
    2) Texan Capitalist Radio
    3) United Capitalists
    4) True Republican Radio
        Which number to choose? > 2
            Incorrect! The answer is True Conservative Radio

Category: Entertainment: Television
Type: multiple
Difficulty: medium
Question: Who co-founded the YouTube Let&#039;s Play channel &quot;Game Grumps&quot; alongside Newgrounds animator Egoraptor?
    1) JonTron
    2) Tobuscus
    3) Markiplier
    4) Pewdiepie
        Which number to choose? > 1
            Correct, keep it on!

Category: Entertainment: Books
Type: multiple
Difficulty: medium
Question: The book &quot;The Little Prince&quot; was written by...
    1) F. Scott Fitzgerald
    2) Jane Austen
    3) Antoine de Saint-Exup&eacute;ry
    4) Miguel de Cervantes Saavedra
        Which number to choose? > 3
            Correct, keep it on!

Category: Entertainment: Video Games
Type: boolean
Difficulty: easy
Question: In Pok&eacute;mon, Bulbasaur is the only starter pokemon that is a Grass/Poison type.
    1) False
    2) True
        Which number to choose? > 4
        Invalid input, try again > 2
            Correct, keep it on!

Category: Entertainment: Cartoon & Animations
Type: multiple
Difficulty: easy
Question: In the show &quot;Foster&#039;s Home For Imaginary Friends&quot;, which character had an obsession with basketball?
    1) Wilt
    2) Cheese
    3) Mac
    4) Coco
        Which number to choose? > 1
            Correct, keep it on!

Category: Science: Computers
Type: multiple
Difficulty: hard
Question: Which RAID array type is associated with data mirroring?
    1) RAID 1
    2) RAID 10
    3) RAID 0
    4) RAID 5
        Which number to choose? > 3
            Incorrect! The answer is RAID 1

Category: Entertainment: Video Games
Type: multiple
Difficulty: medium
Question: In Left 4 Dead, which campaign has the protagonists going through a subway in order to reach a hospital for evacuation?
    1) No Mercy
    2) Blood Harvest
    3) Subway Sprint
    4) Hospital Havoc
        Which number to choose? > 2
            Incorrect! The answer is No Mercy

Category: Geography
Type: multiple
Difficulty: medium
Question: Which of the following is the longest river in Europe?
    1) Ural
    2) Danube
    3) Volga
    4) Dnieper
        Which number to choose? > 4
            Incorrect! The answer is Volga

Category: Sports
Type: multiple
Difficulty: easy
Question: Who is often called &quot;the Maestro&quot; in the men&#039;s tennis circuit?
    1) Bill Tilden
    2) Boris Becker
    3) Pete Sampras
    4) Roger Federer
        Which number to choose? > 4
            Correct, keep it on!

You got 5/10 correct
Fair enough, a lil porcupine for you (•ᴥ• )́`́'́`́'́⻍

Would you like to play again? (yes/no) > yes


  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
  0     0    0     0    0     0      0      0 --:--:-- --:--:-- --:--:--    100  2731    0  2731    0     0  11331      0 --:--:-- --:--:-- --:--:-- 11331

Category: Geography
Type: multiple
Difficulty: easy
Question: The derisive acronym &quot;PIIGS&quot; refers to which of the following European countries and their economic statuses?
    1) Portugal, Ireland, Italy, Greece, Spain
    2) Poland, Iceland, Italy, Greenland, Spain
    3) Poland, Iceland, Italy, Greece, Serbia
    4) Portugal, Iceland, Ireland, Greece, Serbia
        Which number to choose? > 4
            Incorrect! The answer is Portugal, Ireland, Italy, Greece, Spain

Category: Entertainment: Video Games
Type: multiple
Difficulty: easy
Question: What Nationality is D.Va from Overwatch?
    1) Korean
    2) Japanese
    3) Vietnamese 
    4) Chinese
        Which number to choose? > 2
            Incorrect! The answer is Korean

Category: Entertainment: Music
Type: multiple
Difficulty: hard
Question: Which of these songs is NOT included in the Suicide Squad OST?
    1) Skies on Fire - AC/DC
    2) Fortunate Son - Creedence Clearwater Revival
    3) Without Me - Eminem
    4) Heathens - Twenty One Pilots
        Which number to choose? > 1
            Correct, keep it on!

Category: Entertainment: Music
Type: boolean
Difficulty: hard
Question: The song &quot;Mystery Train&quot; was released by artist &quot;Little Junior&#039;s Blue Flames&quot; in 1953.
    1) False
    2) True
        Which number to choose? > 2
            Correct, keep it on!

Category: Animals
Type: multiple
Difficulty: hard
Question: What type of creature is a Bonobo?
    1) Parrot
    2) Wildcat
    3) Lion
    4) Ape
        Which number to choose? > 3
            Incorrect! The answer is Ape

Category: Entertainment: Japanese Anime & Manga
Type: multiple
Difficulty: hard
Question: In &quot;One Piece&quot;, what does &quot;the Pirate King&quot; mean to the captain of the Straw Hat Pirates?
    1) Friendship
    2) Adventure
    3) Promise
    4) Freedom
        Which number to choose? > 4
            Correct, keep it on!

Category: Entertainment: Books
Type: multiple
Difficulty: hard
Question: In the book series &quot;Odd Thomas&quot;, Danny Jessup has what genetic disease? 
    1)  Osteogenesis Imperfecta
    2) Adrenoleukodystrophy
    3) Cystic Fibrosis
    4) Spinocerebellar ataxia
        Which number to choose? > 1
            Correct, keep it on!

Category: Mythology
Type: multiple
Difficulty: medium
Question: The Maori hold that which island nation was founded by Kupe, who discovered it under a long white cloud?
    1) New Zealand
    2) Hawaii
    3) Fiji
    4) Vanuatu
        Which number to choose? > 2
            Incorrect! The answer is New Zealand

Category: Geography
Type: multiple
Difficulty: hard
Question: Which of these is NOT a real tectonic plate?
    1) Eurasian Plate
    2) Atlantic Plate
    3) North American Plate
    4) Nazca Plate
        Which number to choose? > 2
            Correct, keep it on!

Category: Entertainment: Film
Type: multiple
Difficulty: medium
Question: What is the birth name of Michael Caine?
    1) Morris Coleman
    2) Carl Myers
    3) Martin Michaels
    4) Maurice Micklewhite
        Which number to choose? > 1
            Incorrect! The answer is Maurice Micklewhite

You got 5/10 correct
Fair enough, a lil porcupine for you (•ᴥ• )́`́'́`́'́⻍

Would you like to play again? (yes/no) > no

*/