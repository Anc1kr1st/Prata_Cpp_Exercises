// dma.h -- dedicnost a dynamické pridelování pameti
#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class basebaseDMA
{
private:
	char* label;
	int rating;

public:
	basebaseDMA(const char* l = "null", int r = 0);
	basebaseDMA(const basebaseDMA & rs);
	virtual ~basebaseDMA();
	virtual void View() const;
	basebaseDMA& operator=(const basebaseDMA& rs);
	friend std::ostream& operator<<(std::ostream& os, const basebaseDMA& rs);
};


// základní trída s DMA
class baseDMA :public basebaseDMA
{
private:
public:
	baseDMA(const char* l = "null", int r = 0);
	baseDMA(const baseDMA& rs);
	virtual ~baseDMA();
	// baseDMA& operator=(const baseDMA& rs);
	// friend std::ostream& operator<<(std::ostream& os, const baseDMA& rs);
};


// odvozená trída bez DMA
// není potreba destruktor
// používá implicitní kopírovací konstruktor
// používá implicitní operátor pøiøazení
class lacksDMA :public basebaseDMA
{
private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];
public:
	lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);
	lacksDMA(const char* c, const baseDMA& rs);
	friend std::ostream& operator<<(std::ostream& os, const lacksDMA& rs);
};


// odvozená trída s DMA
class hasDMA :public basebaseDMA
{
private:
	char* style;
public:
	hasDMA(const char* s = "none", const char* l = "null", int r = 0);
	hasDMA(const char* s, const baseDMA& rs);
	hasDMA(const hasDMA& hs);
	~hasDMA();
	hasDMA& operator=(const hasDMA& rs);
	friend std::ostream& operator<<(std::ostream& os, const hasDMA& rs);
};

#endif
