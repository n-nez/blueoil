/* Copyright 2018 The Blueoil Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef DLK_FUNC_DEPTH_TO_SPACE_H_INCLUDED
#define DLK_FUNC_DEPTH_TO_SPACE_H_INCLUDED

#include "global.h"
#include "time_measurement.h"

template<class T>
void func_DepthToSpace(T input[], T output[], T_UINT a, T_UINT b, T_UINT kernel_size, T_UINT stride, T_UINT out_height, T_UINT out_width, T_UINT out_depth)
{
  Measurement::Start("ExtractImagePatches");

  T_UINT input_index = 0;

  for(T_UINT wi = 0; wi < out_height; wi += stride)
    for(T_UINT wj = 0; wj < out_width; wj += stride)
    {
      for(T_UINT ki = 0; ki < kernel_size; ki++)
        for(T_UINT kj = 0; kj < kernel_size; kj++)
          for(T_UINT kz = 0; kz < out_depth; kz++)
          {
            T_INT row = wi + ki;
            T_INT col = wj + kj;

            output[row * (out_width * out_depth) + col * (out_depth) + kz] = input[input_index++];
          }
      }

  Measurement::Stop();
}

#endif // DLK_FUNC_DEPTH_TO_SPACE_H_INCLUDED
