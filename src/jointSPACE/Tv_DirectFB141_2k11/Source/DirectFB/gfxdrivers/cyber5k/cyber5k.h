/*
   (c) Copyright 2001-2009  The world wide DirectFB Open Source Community (directfb.org)
   (c) Copyright 2000-2004  Convergence (integrated media) GmbH

   All rights reserved.

   Written by Denis Oliver Kropp <dok@directfb.org>,
              Andreas Hundt <andi@fischlustig.de>,
              Sven Neumann <neo@directfb.org>,
              Ville Syrjälä <syrjala@sci.fi> and
              Claudio Ciccani <klan@users.sf.net>.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the
   Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
*/

#ifndef ___CYBER5K_H__
#define ___CYBER5K_H__

#include <dfb_types.h>
#include <core/layers.h>

/* HACK */
extern volatile u8 *cyber_mmio;


typedef struct {
     volatile u8 *mmio_base;
} CyberDriverData;

typedef struct {
     /* state validation */
     int v_dst;
     int v_src;
     int v_color;
     int v_src_colorkey;
     int v_blitting_cmd;

     /* stored values */
     u32 dst_pixeloffset;
     u32 dst_pixelpitch;
     u32 src_pixeloffset;
     u32 src_pixelpitch;

     u32 blitting_cmd;
} CyberDeviceData;


extern DisplayLayerFuncs cyberUnderlayFuncs;

#endif
