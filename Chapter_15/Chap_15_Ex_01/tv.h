// tv.h -- tr�dy Tv a Remote
#ifndef TV_H_
#define TV_H_

class Tv
{
public:
	friend class Remote; // tr�da Remote m� pr�stup k soukr. c�stem Tv
	enum ZapVyp { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, VCR };

	Tv(ZapVyp s = Off, int mc = 100) : zap_vyp(s), volume(5),
		maxchannel(mc), channel(2), mode(Cable), input(TV) {}
	void onoff() { zap_vyp = (zap_vyp == On) ? Off : On; }
	bool ison() const { return zap_vyp == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
	void set_input() { input = (input == TV) ? VCR : TV; }
	void settings() const; // v�pis v�ech nastaven�
	void style_turn(Remote& r);
private:
	ZapVyp zap_vyp; 			// zapnuto nebo vypnuto
	int volume; 		// bude digitalizov�na 
	int maxchannel; 	// maxim�ln� po�et program�
	int channel; 		// aktu�ln� nastaven� program�
	int mode; 			// z ant�ny nebo kabelem
	int input; 			// TV nebo VCR
};

class Remote
{
private:
	int mode; // ovl�d�n� TV nebo VCR
	int style;
public:
	friend class Tv;
	enum Style { Normal, Interactive };
	Remote(int m = Tv::TV, int s = Normal) : mode(m), style(s) {}
	bool volup(Tv& t) { return t.volup(); }
	bool voldown(Tv& t) { return t.voldown(); }
	void onoff(Tv& t) { t.onoff(); }
	void chanup(Tv& t) { t.chanup(); }
	void chandown(Tv& t) { t.chandown(); }
	void set_chan(Tv& t, int c) { t.channel = c; }
	void set_mode(Tv& t) { t.set_mode(); }
	void set_input(Tv& t) { t.set_input(); }
	void show_style();
};

inline void Tv::style_turn(Remote& r)
{
	if (zap_vyp == Off)
		return;
	if (r.style == Remote::Normal)
		r.style = Remote::Interactive;
	else r.style = Remote::Normal;
}

#endif
