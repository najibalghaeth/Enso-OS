/* LoginMask.c generated by valac 0.30.1, the Vala compiler
 * generated from LoginMask.vala, do not modify */

/*
* Copyright (c) 2011-2017 elementary LLC (http://launchpad.net/pantheon-greeter)
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public
* License as published by the Free Software Foundation; either
* version 2 of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* General Public License for more details.
*
* You should have received a copy of the GNU General Public
* License along with this program; if not, write to the
* Free Software Foundation, Inc., 59 Temple Place - Suite 330,
* Boston, MA 02111-1307, USA.
*
*/

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <lightdm.h>


#define TYPE_PROMPT_TYPE (prompt_type_get_type ())

#define TYPE_PROMPT_TEXT (prompt_text_get_type ())

#define TYPE_LOGIN_MASK (login_mask_get_type ())
#define LOGIN_MASK(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_LOGIN_MASK, LoginMask))
#define IS_LOGIN_MASK(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_LOGIN_MASK))
#define LOGIN_MASK_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), TYPE_LOGIN_MASK, LoginMaskIface))

typedef struct _LoginMask LoginMask;
typedef struct _LoginMaskIface LoginMaskIface;

#define TYPE_MESSAGE_TEXT (message_text_get_type ())

typedef enum  {
	PROMPT_TYPE_SECRET,
	PROMPT_TYPE_QUESTION,
	PROMPT_TYPE_CONFIRM_LOGIN,
	PROMPT_TYPE_FPRINT
} PromptType;

typedef enum  {
	PROMPT_TEXT_USERNAME,
	PROMPT_TEXT_PASSWORD,
	PROMPT_TEXT_OTHER
} PromptText;

typedef enum  {
	MESSAGE_TEXT_FPRINT_SWIPE,
	MESSAGE_TEXT_FPRINT_SWIPE_AGAIN,
	MESSAGE_TEXT_FPRINT_SWIPE_TOO_SHORT,
	MESSAGE_TEXT_FPRINT_NOT_CENTERED,
	MESSAGE_TEXT_FPRINT_REMOVE,
	MESSAGE_TEXT_FPRINT_PLACE,
	MESSAGE_TEXT_FPRINT_PLACE_AGAIN,
	MESSAGE_TEXT_FPRINT_NO_MATCH,
	MESSAGE_TEXT_FPRINT_TIMEOUT,
	MESSAGE_TEXT_FPRINT_ERROR,
	MESSAGE_TEXT_FAILED,
	MESSAGE_TEXT_OTHER
} MessageText;

struct _LoginMaskIface {
	GTypeInterface parent_iface;
	void (*show_prompt) (LoginMask* self, PromptType type, PromptText prompttext, const gchar* text);
	void (*show_message) (LoginMask* self, LightDMMessageType type, MessageText messagetext, const gchar* text);
	void (*not_authenticated) (LoginMask* self);
	void (*login_aborted) (LoginMask* self);
	const gchar* (*get_login_name) (LoginMask* self);
	const gchar* (*get_login_session) (LoginMask* self);
};



GType prompt_type_get_type (void) G_GNUC_CONST;
GType prompt_text_get_type (void) G_GNUC_CONST;
GType message_text_get_type (void) G_GNUC_CONST;
GType login_mask_get_type (void) G_GNUC_CONST;
void login_mask_show_prompt (LoginMask* self, PromptType type, PromptText prompttext, const gchar* text);
void login_mask_show_message (LoginMask* self, LightDMMessageType type, MessageText messagetext, const gchar* text);
void login_mask_not_authenticated (LoginMask* self);
void login_mask_login_aborted (LoginMask* self);
const gchar* login_mask_get_login_name (LoginMask* self);
const gchar* login_mask_get_login_session (LoginMask* self);


GType prompt_type_get_type (void) {
	static volatile gsize prompt_type_type_id__volatile = 0;
	if (g_once_init_enter (&prompt_type_type_id__volatile)) {
		static const GEnumValue values[] = {{PROMPT_TYPE_SECRET, "PROMPT_TYPE_SECRET", "secret"}, {PROMPT_TYPE_QUESTION, "PROMPT_TYPE_QUESTION", "question"}, {PROMPT_TYPE_CONFIRM_LOGIN, "PROMPT_TYPE_CONFIRM_LOGIN", "confirm-login"}, {PROMPT_TYPE_FPRINT, "PROMPT_TYPE_FPRINT", "fprint"}, {0, NULL, NULL}};
		GType prompt_type_type_id;
		prompt_type_type_id = g_enum_register_static ("PromptType", values);
		g_once_init_leave (&prompt_type_type_id__volatile, prompt_type_type_id);
	}
	return prompt_type_type_id__volatile;
}


GType prompt_text_get_type (void) {
	static volatile gsize prompt_text_type_id__volatile = 0;
	if (g_once_init_enter (&prompt_text_type_id__volatile)) {
		static const GEnumValue values[] = {{PROMPT_TEXT_USERNAME, "PROMPT_TEXT_USERNAME", "username"}, {PROMPT_TEXT_PASSWORD, "PROMPT_TEXT_PASSWORD", "password"}, {PROMPT_TEXT_OTHER, "PROMPT_TEXT_OTHER", "other"}, {0, NULL, NULL}};
		GType prompt_text_type_id;
		prompt_text_type_id = g_enum_register_static ("PromptText", values);
		g_once_init_leave (&prompt_text_type_id__volatile, prompt_text_type_id);
	}
	return prompt_text_type_id__volatile;
}


/**
     * Present a prompt to the user. The interface can answer via the
     * respond method of the LoginGateway.
     */
void login_mask_show_prompt (LoginMask* self, PromptType type, PromptText prompttext, const gchar* text) {
	g_return_if_fail (self != NULL);
	LOGIN_MASK_GET_INTERFACE (self)->show_prompt (self, type, prompttext, text);
}


void login_mask_show_message (LoginMask* self, LightDMMessageType type, MessageText messagetext, const gchar* text) {
	g_return_if_fail (self != NULL);
	LOGIN_MASK_GET_INTERFACE (self)->show_message (self, type, messagetext, text);
}


void login_mask_not_authenticated (LoginMask* self) {
	g_return_if_fail (self != NULL);
	LOGIN_MASK_GET_INTERFACE (self)->not_authenticated (self);
}


/**
     * The login-try was aborted because another LoginMask wants to login.
     */
void login_mask_login_aborted (LoginMask* self) {
	g_return_if_fail (self != NULL);
	LOGIN_MASK_GET_INTERFACE (self)->login_aborted (self);
}


const gchar* login_mask_get_login_name (LoginMask* self) {
	g_return_val_if_fail (self != NULL, NULL);
	return LOGIN_MASK_GET_INTERFACE (self)->get_login_name (self);
}


const gchar* login_mask_get_login_session (LoginMask* self) {
	g_return_val_if_fail (self != NULL, NULL);
	return LOGIN_MASK_GET_INTERFACE (self)->get_login_session (self);
}


static void login_mask_base_init (LoginMaskIface * iface) {
	static gboolean initialized = FALSE;
	if (!initialized) {
		initialized = TRUE;
		g_object_interface_install_property (iface, g_param_spec_string ("login-name", "login-name", "login-name", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
		g_object_interface_install_property (iface, g_param_spec_string ("login-session", "login-session", "login-session", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	}
}


/**
 * A LoginMask is for example a UI such as the LoginBox that communicates with
 * the user.
 * It forms with the LoginGateway a protocol for logging in users. The steps
 * are roughly:
 * 1. gateway.login_with_mask - Call this as soon as you know the username
 *           The gateway will get the login_name via the property of your
 *           mask.
 * 2. mask.show_prompt or mask.show_message - one of both is called and the
 *           mask has to display that to the user.
 *           show_prompt also demands that you answer
 *           via gateway.respond.
 * 3. Repeat Step 2 until the gateway fires login_successful
 * 4. Call gateway.start_session after login_successful is called
 *
 *
 */
GType login_mask_get_type (void) {
	static volatile gsize login_mask_type_id__volatile = 0;
	if (g_once_init_enter (&login_mask_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (LoginMaskIface), (GBaseInitFunc) login_mask_base_init, (GBaseFinalizeFunc) NULL, (GClassInitFunc) NULL, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
		GType login_mask_type_id;
		login_mask_type_id = g_type_register_static (G_TYPE_INTERFACE, "LoginMask", &g_define_type_info, 0);
		g_type_interface_add_prerequisite (login_mask_type_id, G_TYPE_OBJECT);
		g_once_init_leave (&login_mask_type_id__volatile, login_mask_type_id);
	}
	return login_mask_type_id__volatile;
}


