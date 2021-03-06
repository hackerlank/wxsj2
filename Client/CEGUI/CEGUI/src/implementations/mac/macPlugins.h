/*
-----------------------------------------------------------------------------
This source file is part of CrazyEddiesGUI
    (but borrowed from OGRE, see http://www.ogre3d.org/)

Copyright � 2000-2002 The OGRE Team
Also see acknowledgements in Readme.html

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General  License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU Lesser General  License for more details.

You should have received a copy of the GNU Lesser General  License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/lesser.txt.
-----------------------------------------------------------------------------
*/

#include <CoreFoundation/CoreFoundation.h>

namespace CEGUI {

     CFBundleRef mac_loadExeBundle(const char *path);
     void * mac_getBundleSym(CFBundleRef bundle, const char *name);
     bool mac_unloadExeBundle(CFBundleRef bundle);
     const char *mac_errorBundle();
}
