/*
 * Play_Sound.h
 *
 *  Created on: 2011. 12. 19.
 *      Author: Administrator
 */

#ifndef PLAY_SOUND_H_
#define PLAY_SOUND_H_
#endif /* PLAY_SOUND_H_ */

#define SOLO_VOL 255
#define HARMONY_VOL 255

#define code_C 100
#define code_D 101
#define code_Dm 102
#define code_E 103
#define code_Em 104
#define code_F 105
#define code_Fm 106
#define code_G 107
#define code_G7 108
#define code_G7s 109
#define code_A 110
#define code_Am 111
#define code_A7 112
#define code_A7s 113
#define code_B 114
#define code_B7 115
#define code_B7p 116



//#include <PA9.h>
#include <maxmod9.h>
#include "soundbank_bin.h"
#include "soundbank.h"

#define NUM_TASK 16

struct parameters {
	int Sound_id;
	int rate;
	int handle; // handle
	int volume; // volume
	int panning; // panning
};



mm_sound_effect Do = { { SFX_DO }, // id
		(int) (1.0f * (1 << 10)), // rate
		0, // handle
		SOLO_VOL, // volume
		0, // panning
		};

mm_sound_effect Re = { { SFX_RE }, // id
		(int) (1.0f * (1 << 10)), // rate
		0, // handle
		SOLO_VOL, // volume
		0, // panning
		};
mm_sound_effect Mi = { { SFX_MI }, // id
		(int) (1.0f * (1 << 10)), // rate
		0, // handle
		SOLO_VOL, // volume
		0, // panning
		};
mm_sound_effect Fa = { { SFX_FA }, // id
		(int) (1.0f * (1 << 10)), // rate
		0, // handle
		SOLO_VOL, // volume
		0, // panning
		};
mm_sound_effect Sol = { { SFX_SOL }, // id
		(int) (1.0f * (1 << 10)), // rate
		0, // handle
		SOLO_VOL, // volume
		0, // panning
		};
mm_sound_effect La = { { SFX_LA }, // id
		(int) (1.0f * (1 << 10)), // rate
		0, // handle
		SOLO_VOL, // volume
		0, // panning
		};
mm_sound_effect Si = { { SFX_SI }, // id
		(int) (1.0f * (1 << 10)), // rate
		0, // handle
		SOLO_VOL, // volume
		0, // panning
		};
mm_sound_effect Hdo = { { SFX_HDO }, // id
		(int) (1.0f * (1 << 10)), // rate
		0, // handle
		SOLO_VOL, // volume
		0, // panning
		};
mm_sound_effect Do_s = { { SFX_DO_S }, // id
		(int) (1.0f * (1 << 10)), // rate
		0, // handle
		SOLO_VOL, // volume
		0, // panning
		};
mm_sound_effect Re_s = { { SFX_RE_S }, // id
		(int) (1.0f * (1 << 10)), // rate
		0, // handle
		SOLO_VOL, // volume
		0, // panning
		};
mm_sound_effect Fa_s = { { SFX_FA_S }, // id
		(int) (1.0f * (1 << 10)), // rate
		0, // handle
		SOLO_VOL, // volume
		0, // panning
		};
mm_sound_effect Sol_s = { { SFX_SOL_S }, // id
		(int) (1.0f * (1 << 10)), // rate
		0, // handle
		SOLO_VOL, // volume
		0, // panning
		};
mm_sound_effect La_s = { { SFX_LA_S }, // id
		(int) (1.0f * (1 << 10)), // rate
		0, // handle
		SOLO_VOL, // volume
		0, // panning
		};

mm_sound_effect HARMONY_C = { { SFX_DO, SFX_MI, SFX_SOL }, // id
		(int) (1.0f * (1 << 10)), // rate
		0, // handle
		HARMONY_VOL, // volume
		0, // panning
		};
