#include <algorithm>

#include "text.h"
//#include "shaders.h"
#include "../ap/def.h"

using namespace en;

en::Text::Text(en::Group g, const Font &font, en::Color *c, const char *quote)
	: Draws(g, 0, &regfluke) ,
	f(font),
	q(quote),
	width(0),
	scale(1)
	{
	color = c;
	
	sh(f.gh()*scale);
	
	int l = strlen(q);
	this->draws.reserve(l);
	for( int i = 0; i<l ;i++) {
		char c = q[i];
		const glyph &g = f.getglyph(c);
		Draws *d = new Draws(GDEF, &font.gtexture(), const_cast<Region *>(&g.r));
		//d->name = "glyph";
		d->scolor(this->color);
		//d->sfit(true);
		//d->sprogram(&fntprgrm);
		//d->so(.77);
		//d->sw(g.w);
		//d->sh(f.gh());
		//printf("x %i y %i w %i h %i", g->r.x, g->r.y, g->r.w, g->r.h);
		this->draws.push_back(d);
	}
}

en::Text::~Text() {
	delete []q;
	std::for_each( this->draws.begin(), this->draws.end(), DeleteVector<Draws*>() );
}

//bool shouldwrap(const Text &, const glyph &);
void en::Text::position() {
	width = 0;
	
	//LOG("positioning " << q)
	int l = draws.size();
	//std::vector<const &glyph> word;
	for( int i = 0; i < l; i++) {
		char c = q[i];
		bool space = ' ' == q[i];
		
		if ( ! space ) {
			
		}
		
		const glyph &g = f.getglyph(c);
		Draws *d = this->draws[i];
		
		d->scolor(color);
		int x_ = (width-g.sb) * scale;
		d->sx(gx() + x_ );
		d->sy(gy());
		
		d->sw(g.w*scale);
		d->sh(f.gh()*scale);
		
		if ( space ) {
			
		}
		
		width += g.w-g.sb-g.sf;
		//std::cout << "text Draws glyph '" << c << "', x: " << d->gx() << std::endl;
	}
	
	sw(width * scale);
	sh(f.gh() * scale);
}

/*inline shouldwrap(const Text &t, const glyph &g) {
	LOG("test")
}*/

//@override
void en::Text::draw() {
	std::vector<Draws *>::iterator it;
	for ( it = draws.begin(); it < draws.end(); it ++) {
		Draws *d = *it;
		d->draw();
	}
}


/* ###########################
   ## Getters & Setters
   ########################### */
int en::Text::gtextw() { return width; }
const char *en::Text::gquote() { return q; }
//void en::Text::smaxw(int i) { maxw = i; }
