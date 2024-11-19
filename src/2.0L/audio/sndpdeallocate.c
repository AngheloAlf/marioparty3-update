/*====================================================================
 * sndpdeallocate.c
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

#include "sndp.h"
#include <os_internal.h>
#include <ultraerror.h>
#include "audioTemp.h"

void alSndpDeallocate(ALSndId id)
{
    ALSndPlayer* temp = (ALSndPlayer*)D_800A2884_A3484->unk_0C;
    ALSoundState  *sState = temp->sndState;

    ALFailIf((sState + id)->state != AL_STOPPED, ERR_ALSNDPDEALLOCATE);

    sState[id].sound = 0;
    if (temp->target == id) /* if we are deleting the target sound */
        temp->target = -1;      
}

