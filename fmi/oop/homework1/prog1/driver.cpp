#include <iostream>
#include "Song.h"
#include "Album.h"
using namespace std;

int main()
{
	Album al;
	al.setName("Octavarium");
	Song a("The Root of All Evil", "Dream Theatre", 2005, 505, NULL);
	Song b("The Answer Lies Within", "Dream Theatre", 2005, 333, NULL);
	Song c("These Walls", "Dream Theatre", 2005, 456, NULL);
	Song d("I Walk Beside You", "Dream Theatre", 2005, 269, NULL);
	Song e("Panic Attack", "Dream Theatre", 2005, 493, NULL);
	Song f("Never Enough", "Dream Theatre", 2005, 406, NULL);
	Song g("Sacrificed Sons", "Dream Theatre", 2005, 642, NULL);
	Song h("Octavarium", "Dream Theatre", 2005, 1440, NULL);
	Song i("I Walk Beside You", "Bai Go6o", 2012, 269, NULL);
	Song j("Panic Attack", "Hipodil", 2014, 493, NULL);
	Song k("These Walls", "Cherno Feredje", 2013, 456, NULL);
	Song l("The Answer Lies Within", "Dream Theatre", 2005, 333, NULL);
	Song m("Never Enough", "Dream Theatre", 2005, 406, NULL);
	al.addSong(a);
	al.addSong(b);
	al.addSong(c);
	al.addSong(d);
	al.addSong(e);
	al.addSong(f);
	al.addSong(g);
	al.addSong(h);
	al.addSong(i);
	al.addSong(j);
	al.addSong(k);
	al.addSong(l);
	al.addSong(m);
	al.print();
	cout<<"~~~~~~~~~~~\n";
	al.deleteDuplicates();
	al.print();
	cout<<"~~~~~~~~~~~\n";
	al.detectCovers();
	al.print();
	return 0;
}