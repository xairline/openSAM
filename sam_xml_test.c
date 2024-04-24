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

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "openSAM.h"

int
main(int argc, char **argv) {

    if (!collect_sam_xml("E:/X-Plane-12-test")) {
        log_msg("Error reading sam.xml files");
        exit(2);
    }

    printf("%d sceneries collected\n", n_sceneries);

    for (scenery_t *sc = sceneries; sc < sceneries + n_sceneries; sc++) {
        printf("%s\n%d jetways collected, bbox: %0.3f,%0.3f -> %0.3f, %0.3f\n", sc->name, sc->n_sam_jws,
               sc->bb_lat_min, sc->bb_lon_min, sc->bb_lat_max, sc->bb_lon_max);

        for (sam_jw_t *jw = sc->sam_jws; jw < sc->sam_jws + sc->n_sam_jws; jw++) {
            log_msg("%s %5.6f %5.6f door: %d", jw->name, jw->latitude, jw->longitude, jw->door);
        }
        puts("\n");
    }

	return (1);
}
