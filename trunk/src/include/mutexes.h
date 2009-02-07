/*
    ChibiOS/RT - Copyright (C) 2006-2007 Giovanni Di Sirio.

    This file is part of ChibiOS/RT.

    ChibiOS/RT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS/RT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * @file mutexes.h
 * @brief Mutexes macros and structures.
 * @addtogroup Mutexes
 * @{
 */

#ifndef _MUTEXES_H_
#define _MUTEXES_H_

#if CH_USE_MUTEXES

/**
 * @brief Mutex structure.
 */
typedef struct Mutex {
  ThreadsQueue          m_queue;        /**< Queue of the threads sleeping on
                                             this Mutex.*/
  Thread                *m_owner;       /**< Owner @p Thread pointer or
                                             @p NULL.*/
  struct Mutex          *m_next;        /**< Next @p Mutex into an owner-list
                                             or @p NULL.*/
} Mutex;

#ifdef __cplusplus
extern "C" {
#endif
  void chMtxInit(Mutex *mp);
  void chMtxLock(Mutex *mp);
  void chMtxLockS(Mutex *mp);
  bool_t chMtxTryLock(Mutex *mp);
  bool_t chMtxTryLockS(Mutex *mp);
  Mutex *chMtxUnlock(void);
  Mutex *chMtxUnlockS(void);
  void chMtxUnlockAll(void);
#ifdef __cplusplus
}
#endif

/**
 * Returns @p TRUE if the mutex queue contains at least a waiting thread.
 */
#define chMtxQueueNotEmptyS(mp) notempty(&(mp)->m_queue)

#endif /* CH_USE_MUTEXES */

#endif /* _MUTEXES_H_ */

/** @} */
