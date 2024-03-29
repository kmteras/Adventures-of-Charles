#pragma once

#include "Utility/Utility.h"
#include "GUI/GUIElement.h"

namespace Eucolus
{
	namespace GUI
	{
		class Label : Element
		{
		public:
			Label();
			~Label();

			void Update();
			void Render();

		private:
			std::string m_text;
		};
	}
}
