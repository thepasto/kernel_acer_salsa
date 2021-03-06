/* Copyright (c) 2010, Code Aurora Forum. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of Code Aurora Forum, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*
 * SDIO CMUX API
 */

#ifndef __SDIO_CMUX__
#define __SDIO_CMUX__

/*
 * sdio_cmux_open - Open the mux channel
 *
 * @id: Mux Channel id to be opened
 * @receive_cb: Notification when data arrives
 * @write_done: Notification when data is written
 * @priv: caller's private context pointer
 */
int sdio_cmux_open(const int id,
		   void (*receive_cb)(int , void *, int),
		   void (*write_done)(int , void *, int),
		   void *priv);

/*
 * sdio_cmux_close - Close the mux channel
 *
 * @id: Channel id to be closed
 */
int sdio_cmux_close(int id);

/*
 * sdio_cmux_write_avail - Write space avaialable for this channel
 *
 * @id: Channel id to look for the available write space
 */
int sdio_cmux_write_avail(int id);

/*
 * sdio_cmux_write - Write the data onto the CMUX channel
 *
 * @id: Channel id onto which the data has to be written
 * @data: Starting address of the data buffer to be written
 * @len: Length of the data to be written
 */
int sdio_cmux_write(int id, void *data, int len);

/*
 * is_remote_open - Check whether the remote channel is open
 *
 * @id: Channel id to be checked
 */
int is_remote_open(int id);

#endif /* __SDIO_CMUX__ */
