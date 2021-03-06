// Averaged Voxel GLobal Illumination
// Copyright (C) 2014  Evan Arthur Kosin
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

// Array of texture types for easy reference.
aiTextureType textureType[4] = {aiTextureType_DIFFUSE, aiTextureType_HEIGHT, aiTextureType_SPECULAR, aiTextureType_OPACITY};

//Textures List:
//textureInfo - struct of path and OpenGL ID of textures
//textures - vector of textureInfo
//find() - find and return ID of a texture already in textures
//         with path of modelRelativePath
//  returns: textureID or 0
//add() - add texture to textures
class texturesList
{
	struct textureInfo
	{
		aiString texturePath;
		GLuint textureID;
	};
	std::vector<textureInfo> textures;
	public:
		GLuint find(aiString modelRelativePath)
		{
			for (std::vector<textureInfo>::iterator iterator = textures.begin() ; iterator != textures.end(); ++iterator)
			{
				if(modelRelativePath == iterator->texturePath)
				{
					return iterator->textureID;
				}
			}
			return (GLuint) 0;
		}
		void add(aiString modelRelativePath, GLuint textureID)
		{
			textureInfo newTextureInfo;
			newTextureInfo.texturePath = modelRelativePath.C_Str();
			newTextureInfo.textureID = textureID;
			textures.push_back(newTextureInfo);
		}
};

// Array of texture slots
GLenum textureSlots[32] = 
	{GL_TEXTURE0,
	GL_TEXTURE1,
	GL_TEXTURE2,
	GL_TEXTURE3,
	GL_TEXTURE4,
	GL_TEXTURE5,
	GL_TEXTURE6,
	GL_TEXTURE7,
	GL_TEXTURE8,
	GL_TEXTURE9,
	GL_TEXTURE10,
	GL_TEXTURE11,
	GL_TEXTURE12,
	GL_TEXTURE13,
	GL_TEXTURE14,
	GL_TEXTURE15,
	GL_TEXTURE16,
	GL_TEXTURE17,
	GL_TEXTURE18,
	GL_TEXTURE19,
	GL_TEXTURE20,
	GL_TEXTURE21,
	GL_TEXTURE22,
	GL_TEXTURE23,
	GL_TEXTURE24,
	GL_TEXTURE25,
	GL_TEXTURE26,
	GL_TEXTURE27,
	GL_TEXTURE28,
	GL_TEXTURE29,
	GL_TEXTURE30,
	GL_TEXTURE31};