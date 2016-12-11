#pragma once

namespace game
{

//////////////////////////////////////////////////////////////////////////
//************ Class relationships ************
//	Director
//	GraphicsEngine
//		GLGraphics
//		GLESGraphics
//  GraphicsObject
//      Resource
//          Buffer
//              ConstantBuffer
//              TextureBuffer
//              VertexBuffer
//              IndexBuffer
//              StructuredBuffer
//              TypedBuffer
//              RawBuffer
//              IndirectArgumentsBuffer
//          Texture
//              TextureSingle
//                  Texture1
//                  Texture2
//                      TextureRT
//                      TextureDS
//                  Texture3
//              TextureArray
//                  Texture1Array
//                  Texture2Array
//                  TextureCube
//                  TextureCubeArray
//      Shader
//          VertexShader
//          GeometryShader
//          PixelShader
//          ComputeShader
//      DrawingState
//          SamplerState
//          BlendState
//          DepthStencilState
//          RasterizerState
//////////////////////////////////////////////////////////////////////////
}

#include "GMApplication.h"
//#include "GMGraphics.h"
//#include "base/GMDirector.h"
//#include "base/GMGraphicsObject.h"