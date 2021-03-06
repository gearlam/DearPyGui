#pragma once

#include <utility>
#include "mvAppItem.h"

//-----------------------------------------------------------------------------
// Widget Index
//
//     * mvImage
//     * mvImageButton
//
//-----------------------------------------------------------------------------

namespace Marvel {

	//-----------------------------------------------------------------------------
	// mvImage
	//-----------------------------------------------------------------------------
	class mvImage : public mvAppItem
	{

	public:

		MV_APPITEM_TYPE(mvAppItemType::InputInt, "add_image")

		mvImage(const std::string& name, std::string default_value);

		~mvImage() override;

		void               draw              ()               override;
		void               setExtraConfigDict(PyObject* dict) override;
		void               getExtraConfigDict(PyObject* dict) override;
		void               setValue          (const std::string& value);
		const std::string& getValue          () const;


	private:

		std::string m_value;
		mvVec2	    m_uv_min = {0.0f, 0.0f};
		mvVec2	    m_uv_max = {1.0f, 1.0f};
		mvColor     m_tintColor = {255, 255, 255, 255, true};
		mvColor     m_borderColor = {0, 0, 0, 0, true};
		void*       m_texture = nullptr;
		bool        m_dirty = false;

	};

	//-----------------------------------------------------------------------------
	// mvImageButton
	//-----------------------------------------------------------------------------
	class mvImageButton : public mvAppItem
	{

	public:

		MV_APPITEM_TYPE(mvAppItemType::ImageButton, "add_image_button")

		mvImageButton(const std::string& name, std::string  default_value);

		~mvImageButton() override;

		void draw              ()               override;
		void setExtraConfigDict(PyObject* dict) override;
		void getExtraConfigDict(PyObject* dict) override;

	private:

		std::string m_value;
		mvVec2	    m_uv_min = { 0.0f, 0.0f };
		mvVec2	    m_uv_max = {1.0f, 1.0f};
		mvColor     m_tintColor = {255, 255, 255, 255, true};
		mvColor     m_backgroundColor = {0, 0, 0, 0, true};
		void*       m_texture = nullptr;
		int         m_framePadding = -1;
		bool        m_dirty = false;

	};

}