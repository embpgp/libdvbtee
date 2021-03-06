/*****************************************************************************
 * Copyright (C) 2013-2016 Michael Ira Krufky
 *
 * Author: Michael Ira Krufky <mkrufky@linuxtv.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *****************************************************************************/

#ifndef HLSFEEDER_H
#define HLSFEEDER_H

#include "feed.h"
#include "curlhttpget.h"
#include "rbuf.h"

class hlsfeed
{
  friend class pushwalk_iface;
public:
  explicit hlsfeed(const char *url = NULL, curlhttpget_iface *iface = NULL);

private:
#if 0
  const char *toplevel;
#endif
  std::string Url;
  curlhttpget_iface *m_iface;

  void push(uint8_t *buffer, size_t size, size_t nmemb);
  void walk(uint8_t *buffer, size_t size, size_t nmemb);
  void walk(uint8_t *buffer);

  rbuf push_buffer;
  rbuf walk_buffer;
  bool f_kill_thread;
  pthread_t h_push_thread;
  pthread_t h_walk_thread;

  static void* push_thread(void*);
  void* push_thread();

  static void* walk_thread(void*);
  void* walk_thread();
};

#endif // HLSFEEDER_H
