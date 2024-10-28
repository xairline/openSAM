/*
    openSAM: open source SAM emulator for X Plane

    Copyright (C) 2024  Holger Teutsch

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
    USA

*/

struct _stand {
    float lat, lon, hdgt;   // from apt.dat

    unsigned int ref_gen;   // only valid if this matches the generation of the ref frame
    double stand_x, stand_y, stand_z;
    float cos_hdgt, sin_hdgt;

    char id[40];
};

extern int dgs_init(void);
extern float dgs_state_machine(void);
extern void dgs_set_active(void);
extern void dgs_set_inactive(void);

extern void xform_to_ref_frame(stand_t *stand);
extern void global_2_stand(const stand_t * stand, float x, float z, float *x_l, float *z_l);

