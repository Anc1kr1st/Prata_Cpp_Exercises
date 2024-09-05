// tv.h -- trídy Tv a Remote
#ifndef TV_H_
#define TV_H_

class Tv
{
public:
	friend class Remote; // trída Remote má prístup k soukr. cástem Tv
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
	void settings() const; // výpis všech nastavení
	void style_turn(Remote& r);
private:
	ZapVyp zap_vyp; 			// zapnuto nebo vypnuto
	int volume; 		// bude digitalizována 
	int maxchannel; 	// maximální poèet programù
	int channel; 		// aktuální nastavení programù
	int mode; 			// z antény nebo kabelem
	int input; 			// TV nebo VCR
};

class Remote
{
private:
	int mode; // ovládání TV nebo VCR
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
