namespace ap {
	namespace stats {
		void rebuild();
		
		extern gui::Label *fps;
		extern gui::Label *delta;
		extern gui::Label *draws;
		extern gui::Label *sprites;
		
		void rbfps();
		void rbdelta();
		void rbdraws();
		void rbsprites();
	}
}

using namespace ap;

gui::Label *ap::stats::fps = nullptr;
gui::Label *ap::stats::delta = nullptr;
gui::Label *ap::stats::draws = nullptr;
gui::Label *ap::stats::sprites = nullptr;


void ap::stats::rebuild() {
	rbfps();
	rbdelta();
	rbdraws();
	rbsprites();
}

void ap::stats::rbfps() {
	return;
	std::ostringstream strs;
	strs << ap::fps;
	
	std::string thing = std::string();
	
	thing.append(strs.str());
	
	using namespace boilerplate;
	const char *v = cpychr(thing.c_str());
	fps->svalue(v);
	fps->reposition();
}

void ap::stats::rbdelta() {
	return;
	std::ostringstream strs;
	strs << en::delta;
	
	std::string thing = std::string();
	
	thing.append(strs.str());
	
	using namespace boilerplate;
	const char *v = cpychr(thing.c_str());
	delta->svalue(v);
	delta->reposition();
}

void ap::stats::rbdraws() {
	return;
	std::ostringstream strs;
	
	strs << en::Draws::GCOUNT();
	std::string thing = std::string();
	
	thing.append(strs.str());
	
	using namespace boilerplate;
	const char *v = cpychr(thing.c_str());
	draws->svalue(v);
	draws->reposition();
}

void ap::stats::rbsprites() {
	return;
	std::ostringstream strs;
	strs << Sprite::GCOUNT();
	
	std::string thing = std::string();
	
	thing.append(strs.str());
	
	using namespace boilerplate;
	const char *v = cpychr(thing.c_str());
	sprites->svalue(v);
	sprites->reposition();
}

void showcolissions() {
	return;
	/*std::ostringstream strs;
	strs << ap::world->sprites.v.size();
	
	std::string thing = std::string("sprites ");
	
	thing.append(strs.str());
	
	stats::spritesstat = new en::Text(stats::font, &WHITE, thing.c_str() );
	//stats::spritesstat->name = "spritesstat";
	
	int space = stats::font.getglyph(' ')->w;
	
	stats::spritesstat->sx( space );
	stats::spritesstat->sy( space+(stats::font.gh()*3) );
	stats::spritesstat->position();
	
	add(stats::spritesstat);*/
}