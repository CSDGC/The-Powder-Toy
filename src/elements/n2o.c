#include <element.h>

int update_N2O(UPDATE_FUNC_ARGS)
{
	int r,rx,ry,rt;
	for (rx=-2; rx<3; rx++)
		for (ry=-2; ry<3; ry++)
			if (x+rx>=0 && y+ry>=0 && x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
				rt = (r&0xFF);
				if ((r>>8)>=NPART || !r)
					continue;
				if ((r&0xFF)==PT_SPRK)
				{
                    if (parts[r>>8].type==PT_H2||parts[r>>8].type==PT_GAS||parts[r>>8].type==PT_OIL||parts[r>>8].type==PT_DESL||parts[r>>8].type==PT_NITR||parts[r>>8].type==PT_GUNP)
						part_change_type(i,x,y,PT_FIRE);
				}
			}
	return 0;
}
