/*
 * Sifteo SDK Example.
 */

#include <sifteo.h>
#include "assets.gen.h"
using namespace Sifteo;

static Metadata M = Metadata()
    .title("Friends")
    .package("com.sifteo.sdk.sensors", "1.1")
    .icon(Icon)
    .cubeRange(0, CUBE_ALLOCATION);

static VideoBuffer vid[CUBE_ALLOCATION];
static TiltShakeRecognizer motion[CUBE_ALLOCATION];

class CubeSensorListener {
public:
	struct NeighbourCounter {
		int numNeighbours;
	} counters[CUBE_ALLOCATION];
	
	void init() {
		Events::neighborAdd.set(&CubeSensorListener::onAddNeighbour, this);
		Events::neighborRemove.set(&CubeSensorListener::onRemoveNeighbour, this);
		Events::cubeConnect.set(&CubeSensorListener::onConnect, this);
		
		for(CubeID cube : CubeSet::connected()) {
			onConnect(cube);
		}
	}
	
private:
	void onConnect(unsigned id) {
		
		CubeID cube(id);
		uint64_t hwid = cube.hwID();
		
		LOG("Connect!\n");
	
		
		bzero(counters[id]);
		
		vid[id].initMode(BG0_ROM);
		vid[id].attach(id);
		
		BG0ROMDrawable &draw = vid[cube].bg0rom;
		draw0Friends(draw);

	}
	
	bool isActive(NeighborID nid) {
		return nid.isCube();
	}
	
	void onAddNeighbour(unsigned firstID, unsigned firstSide, unsigned secondID, unsigned secondSide) {
		
		// redraw only if a cube is places near a cube, and not the base
		if(isActive(firstID) && isActive(secondID)) {
			
			counters[firstID].numNeighbours++;
			drawNeighbours(firstID);
			counters[secondID].numNeighbours++;
			drawNeighbours(secondID);
		
		}

		
	}
	
	void onRemoveNeighbour(unsigned firstID, unsigned firstSide, unsigned secondID, unsigned secondSide) {
		
		// redraw only if a cube is places near a cube, and not the base
		if(isActive(firstID) && isActive(secondID)) {
			counters[firstID].numNeighbours--;
			drawNeighbours(firstID);
			counters[secondID].numNeighbours--;
			drawNeighbours(secondID);
		}

	}
	
	void draw0Friends(BG0ROMDrawable &draw) {
		unsigned nbColor = draw.BLACK_ON_WHITE;
		draw.fill(vec(0,0),vec(18,18),nbColor | draw.SOLID_FG);
		
		nbColor = draw.RED;
		draw.fill(vec(5,6),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(6,5),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(6,6),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(6,12),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(7,12),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(7,13),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(8,12),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(8,13),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(9,12),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(9,13),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(10,12),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(10,13),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(11,6),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(11,12),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(12,5),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(12,6),vec(1,1),nbColor | draw.SOLID_FG);
	}
	
	void draw1Friends(BG0ROMDrawable &draw) {
		
		unsigned nbColor = draw.BLACK_ON_WHITE;
		draw.fill(vec(0,0),vec(18,18),nbColor | draw.SOLID_FG);
		
		nbColor = draw.RED;
		draw.fill(vec(3,4),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(4,3),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(5,3),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(5,6),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(5,11),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(6,3),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(6,5),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(6,6),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(6,12),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(7,12),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(7,13),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(8,13),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(9,4),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(9,13),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(10,3),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(10,12),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(10,13),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(11,3),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(11,6),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(11,12),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(12,3),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(12,5),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(12,6),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(12,11),vec(1,1),nbColor | draw.SOLID_FG);
		nbColor = draw.WHITE_ON_BLACK;
		draw.fill(vec(5,5),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(11,5),vec(1,1),nbColor | draw.SOLID_FG);
	}
	
	void draw2Friends(BG0ROMDrawable &draw) {
		unsigned nbColor = draw.BLACK_ON_WHITE;
		draw.fill(vec(0,0),vec(18,18),nbColor | draw.SOLID_FG);
		
		nbColor = draw.RED;
		draw.fill(vec(3,4),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(4,3),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(5,3),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(5,11),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(6,3),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(6,12),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(7,2),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(7,8),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(7,9),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(7,13),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(8,7),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(8,9),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(8,13),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(9,4),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(9,13),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(10,3),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(10,13),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(11,3),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(11,12),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(12,3),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(12,11),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(13,2),vec(1,1),nbColor | draw.SOLID_FG);
		nbColor = draw.WHITE_ON_BLACK;
		draw.fill(vec(5,5),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(5,6),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(6,5),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(6,6),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(11,5),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(11,6),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(12,5),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(12,6),vec(1,1),nbColor | draw.SOLID_FG);
	}
	
	void draw3Friends(BG0ROMDrawable &draw) {
		unsigned nbColor = draw.BLACK_ON_WHITE;
		draw.fill(vec(0,0),vec(18,18),nbColor | draw.SOLID_FG);
		
		
		nbColor = draw.RED;
		draw.fill(vec(2,3),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(3,2),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(4,1),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(5,1),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(5,11),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(6,2),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(6,12),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(7,3),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(7,8),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(7,9),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(7,13),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(8,7),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(8,9),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(8,13),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(9,6),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(9,13),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(10,13),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(11,3),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(11,12),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(12,2),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(12,11),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(13,1),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(14,1),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(15,2),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(16,3),vec(1,1),nbColor | draw.SOLID_FG);
		nbColor = draw.WHITE_ON_BLACK;
		draw.fill(vec(4,4),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(4,5),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(5,4),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(5,5),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(7,12),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(8,12),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(9,12),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(10,12),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(13,4),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(13,5),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(14,4),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(14,5),vec(1,1),nbColor | draw.SOLID_FG);

	}

	
	void draw4Friends(BG0ROMDrawable &draw) {
		unsigned nbColor = draw.BLACK_ON_WHITE;
		draw.fill(vec(0,0),vec(18,18),nbColor | draw.SOLID_FG);
		
		nbColor = draw.RED;
		draw.fill(vec(2,3),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(3,2),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(4,2),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(5,2),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(5,13),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(6,1),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(6,12),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(6,14),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(7,8),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(7,9),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(7,11),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(7,15),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(8,7),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(8,9),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(8,11),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(8,15),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(9,6),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(9,11),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(9,15),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(10,11),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(10,15),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(11,12),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(11,14),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(12,1),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(12,13),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(13,2),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(14,2),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(15,2),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(16,3),vec(1,1),nbColor | draw.SOLID_FG);
		nbColor = draw.WHITE_ON_BLACK;
		draw.fill(vec(4,4),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(4,5),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(5,4),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(5,5),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(6,13),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(7,12),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(7,13),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(7,14),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(8,12),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(8,13),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(8,14),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(9,12),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(9,13),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(9,14),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(10,12),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(10,13),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(10,14),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(11,13),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(13,4),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(13,5),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(14,4),vec(1,1),nbColor | draw.SOLID_FG);
		draw.fill(vec(14,5),vec(1,1),nbColor | draw.SOLID_FG);



		
	}

	void drawNeighbours(unsigned id) {
		CubeID cube(id);
		int num = counters[id].numNeighbours;
		String<64> str;
		str << id << " has " << num << " neigbours..\n";
		LOG("%s\n",str.c_str());

		BG0ROMDrawable &draw = vid[cube].bg0rom;
		
		if(num == 0) {
			draw0Friends(draw);
		} else if(num == 1) {
			draw1Friends(draw);
		} else if(num == 2) {
			draw2Friends(draw);
		} else if(num == 3) {
			draw3Friends(draw);
		} else if(num == 4) {
			draw4Friends(draw);
		}
 
		
	}
};


void main()
{
    static CubeSensorListener sensors;

    sensors.init();

    // We're entirely event-driven. Everything is
    // updated by SensorListener's event callbacks.
    while (1)
        System::paint();
}
