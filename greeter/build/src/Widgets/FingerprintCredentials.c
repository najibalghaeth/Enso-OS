/* FingerprintCredentials.c generated by valac 0.30.1, the Vala compiler
 * generated from FingerprintCredentials.vala, do not modify */

/*
* Copyright (c) 2011-2017 elementary LLC. (http://launchpad.net/pantheon-greeter)
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
#include <gtk/gtk.h>
#include <lightdm.h>
#include <stdlib.h>
#include <string.h>
#include <glib/gi18n-lib.h>


#define TYPE_MESSAGE_TEXT (message_text_get_type ())

#define TYPE_CREDENTIALS (credentials_get_type ())
#define CREDENTIALS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_CREDENTIALS, Credentials))
#define IS_CREDENTIALS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_CREDENTIALS))
#define CREDENTIALS_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), TYPE_CREDENTIALS, CredentialsIface))

typedef struct _Credentials Credentials;
typedef struct _CredentialsIface CredentialsIface;

#define TYPE_FINGERPRINT_CREDENTIALS (fingerprint_credentials_get_type ())
#define FINGERPRINT_CREDENTIALS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_FINGERPRINT_CREDENTIALS, FingerprintCredentials))
#define FINGERPRINT_CREDENTIALS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_FINGERPRINT_CREDENTIALS, FingerprintCredentialsClass))
#define IS_FINGERPRINT_CREDENTIALS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_FINGERPRINT_CREDENTIALS))
#define IS_FINGERPRINT_CREDENTIALS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_FINGERPRINT_CREDENTIALS))
#define FINGERPRINT_CREDENTIALS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_FINGERPRINT_CREDENTIALS, FingerprintCredentialsClass))

typedef struct _FingerprintCredentials FingerprintCredentials;
typedef struct _FingerprintCredentialsClass FingerprintCredentialsClass;
typedef struct _FingerprintCredentialsPrivate FingerprintCredentialsPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

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

struct _CredentialsIface {
	GTypeInterface parent_iface;
	void (*show_message) (Credentials* self, LightDMMessageType type, MessageText messagetext, const gchar* text);
};

struct _FingerprintCredentials {
	GtkGrid parent_instance;
	FingerprintCredentialsPrivate * priv;
};

struct _FingerprintCredentialsClass {
	GtkGridClass parent_class;
};

struct _FingerprintCredentialsPrivate {
	GtkLabel* label;
};


static gpointer fingerprint_credentials_parent_class = NULL;
static CredentialsIface* fingerprint_credentials_credentials_parent_iface = NULL;

GType message_text_get_type (void) G_GNUC_CONST;
GType credentials_get_type (void) G_GNUC_CONST;
GType fingerprint_credentials_get_type (void) G_GNUC_CONST;
#define FINGERPRINT_CREDENTIALS_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_FINGERPRINT_CREDENTIALS, FingerprintCredentialsPrivate))
enum  {
	FINGERPRINT_CREDENTIALS_DUMMY_PROPERTY
};
FingerprintCredentials* fingerprint_credentials_new (void);
FingerprintCredentials* fingerprint_credentials_construct (GType object_type);
#define CONSTANTS_PKGDATADIR "/usr/share/enso/greeter"
static void fingerprint_credentials_real_show_message (Credentials* base, LightDMMessageType type, MessageText messagetext, const gchar* text);
static void fingerprint_credentials_finalize (GObject* obj);


GType message_text_get_type (void) {
	static volatile gsize message_text_type_id__volatile = 0;
	if (g_once_init_enter (&message_text_type_id__volatile)) {
		static const GEnumValue values[] = {{MESSAGE_TEXT_FPRINT_SWIPE, "MESSAGE_TEXT_FPRINT_SWIPE", "fprint-swipe"}, {MESSAGE_TEXT_FPRINT_SWIPE_AGAIN, "MESSAGE_TEXT_FPRINT_SWIPE_AGAIN", "fprint-swipe-again"}, {MESSAGE_TEXT_FPRINT_SWIPE_TOO_SHORT, "MESSAGE_TEXT_FPRINT_SWIPE_TOO_SHORT", "fprint-swipe-too-short"}, {MESSAGE_TEXT_FPRINT_NOT_CENTERED, "MESSAGE_TEXT_FPRINT_NOT_CENTERED", "fprint-not-centered"}, {MESSAGE_TEXT_FPRINT_REMOVE, "MESSAGE_TEXT_FPRINT_REMOVE", "fprint-remove"}, {MESSAGE_TEXT_FPRINT_PLACE, "MESSAGE_TEXT_FPRINT_PLACE", "fprint-place"}, {MESSAGE_TEXT_FPRINT_PLACE_AGAIN, "MESSAGE_TEXT_FPRINT_PLACE_AGAIN", "fprint-place-again"}, {MESSAGE_TEXT_FPRINT_NO_MATCH, "MESSAGE_TEXT_FPRINT_NO_MATCH", "fprint-no-match"}, {MESSAGE_TEXT_FPRINT_TIMEOUT, "MESSAGE_TEXT_FPRINT_TIMEOUT", "fprint-timeout"}, {MESSAGE_TEXT_FPRINT_ERROR, "MESSAGE_TEXT_FPRINT_ERROR", "fprint-error"}, {MESSAGE_TEXT_FAILED, "MESSAGE_TEXT_FAILED", "failed"}, {MESSAGE_TEXT_OTHER, "MESSAGE_TEXT_OTHER", "other"}, {0, NULL, NULL}};
		GType message_text_type_id;
		message_text_type_id = g_enum_register_static ("MessageText", values);
		g_once_init_leave (&message_text_type_id__volatile, message_text_type_id);
	}
	return message_text_type_id__volatile;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


FingerprintCredentials* fingerprint_credentials_construct (GType object_type) {
	FingerprintCredentials * self = NULL;
	GtkImage* image = NULL;
	GtkImage* _tmp0_ = NULL;
	GtkGrid* box = NULL;
	GtkGrid* _tmp1_ = NULL;
	GtkStyleContext* _tmp2_ = NULL;
	GtkLabel* _tmp3_ = NULL;
	GtkLabel* _tmp4_ = NULL;
	GtkStyleContext* label_style_context = NULL;
	GtkLabel* _tmp5_ = NULL;
	GtkStyleContext* _tmp6_ = NULL;
	GtkStyleContext* _tmp7_ = NULL;
	GtkLabel* _tmp8_ = NULL;
	self = (FingerprintCredentials*) g_object_new (object_type, NULL);
	_tmp0_ = (GtkImage*) gtk_image_new_from_file (CONSTANTS_PKGDATADIR "/fingerprint.svg");
	g_object_ref_sink (_tmp0_);
	image = _tmp0_;
	g_object_set ((GtkWidget*) image, "margin", 6, NULL);
	_tmp1_ = (GtkGrid*) gtk_grid_new ();
	g_object_ref_sink (_tmp1_);
	box = _tmp1_;
	_tmp2_ = gtk_widget_get_style_context ((GtkWidget*) box);
	gtk_style_context_add_class (_tmp2_, "fingerprint");
	gtk_container_add ((GtkContainer*) box, (GtkWidget*) image);
	_tmp3_ = (GtkLabel*) gtk_label_new ("");
	g_object_ref_sink (_tmp3_);
	_g_object_unref0 (self->priv->label);
	self->priv->label = _tmp3_;
	_tmp4_ = self->priv->label;
	gtk_widget_set_valign ((GtkWidget*) _tmp4_, GTK_ALIGN_CENTER);
	_tmp5_ = self->priv->label;
	_tmp6_ = gtk_widget_get_style_context ((GtkWidget*) _tmp5_);
	_tmp7_ = _g_object_ref0 (_tmp6_);
	label_style_context = _tmp7_;
	gtk_style_context_add_class (label_style_context, "h3");
	gtk_style_context_add_class (label_style_context, "fingerprint-label");
	gtk_grid_attach ((GtkGrid*) self, (GtkWidget*) box, 0, 0, 1, 1);
	_tmp8_ = self->priv->label;
	gtk_grid_attach ((GtkGrid*) self, (GtkWidget*) _tmp8_, 1, 0, 1, 1);
	gtk_grid_set_column_spacing ((GtkGrid*) self, 6);
	_g_object_unref0 (label_style_context);
	_g_object_unref0 (box);
	_g_object_unref0 (image);
	return self;
}


FingerprintCredentials* fingerprint_credentials_new (void) {
	return fingerprint_credentials_construct (TYPE_FINGERPRINT_CREDENTIALS);
}


static void fingerprint_credentials_real_show_message (Credentials* base, LightDMMessageType type, MessageText messagetext, const gchar* text) {
	FingerprintCredentials * self;
	GtkStyleContext* label_style_context = NULL;
	GtkLabel* _tmp0_ = NULL;
	GtkStyleContext* _tmp1_ = NULL;
	GtkStyleContext* _tmp2_ = NULL;
	LightDMMessageType _tmp3_ = 0;
	MessageText _tmp8_ = 0;
	self = (FingerprintCredentials*) base;
	g_return_if_fail (text != NULL);
	_tmp0_ = self->priv->label;
	_tmp1_ = gtk_widget_get_style_context ((GtkWidget*) _tmp0_);
	_tmp2_ = _g_object_ref0 (_tmp1_);
	label_style_context = _tmp2_;
	_tmp3_ = type;
	if (_tmp3_ == LIGHTDM_MESSAGE_TYPE_INFO) {
		GtkStyleContext* _tmp4_ = NULL;
		GtkStyleContext* _tmp5_ = NULL;
		_tmp4_ = label_style_context;
		gtk_style_context_remove_class (_tmp4_, GTK_STYLE_CLASS_ERROR);
		_tmp5_ = label_style_context;
		gtk_style_context_add_class (_tmp5_, GTK_STYLE_CLASS_INFO);
	} else {
		GtkStyleContext* _tmp6_ = NULL;
		GtkStyleContext* _tmp7_ = NULL;
		_tmp6_ = label_style_context;
		gtk_style_context_remove_class (_tmp6_, GTK_STYLE_CLASS_INFO);
		_tmp7_ = label_style_context;
		gtk_style_context_add_class (_tmp7_, GTK_STYLE_CLASS_ERROR);
	}
	_tmp8_ = messagetext;
	switch (_tmp8_) {
		case MESSAGE_TEXT_FPRINT_SWIPE:
		{
			GtkLabel* _tmp9_ = NULL;
			const gchar* _tmp10_ = NULL;
			_tmp9_ = self->priv->label;
			_tmp10_ = _ ("Swipe your finger");
			gtk_label_set_label (_tmp9_, _tmp10_);
			break;
		}
		case MESSAGE_TEXT_FPRINT_PLACE:
		{
			GtkLabel* _tmp11_ = NULL;
			const gchar* _tmp12_ = NULL;
			_tmp11_ = self->priv->label;
			_tmp12_ = _ ("Place your finger");
			gtk_label_set_label (_tmp11_, _tmp12_);
			break;
		}
		case MESSAGE_TEXT_FPRINT_REMOVE:
		{
			GtkLabel* _tmp13_ = NULL;
			const gchar* _tmp14_ = NULL;
			_tmp13_ = self->priv->label;
			_tmp14_ = _ ("Remove your finger and try again.");
			gtk_label_set_label (_tmp13_, _tmp14_);
			break;
		}
		case MESSAGE_TEXT_FPRINT_NOT_CENTERED:
		{
			GtkLabel* _tmp15_ = NULL;
			const gchar* _tmp16_ = NULL;
			_tmp15_ = self->priv->label;
			_tmp16_ = _ ("Center your finger and try again.");
			gtk_label_set_label (_tmp15_, _tmp16_);
			break;
		}
		default:
		{
			GtkLabel* _tmp17_ = NULL;
			const gchar* _tmp18_ = NULL;
			_tmp17_ = self->priv->label;
			_tmp18_ = text;
			gtk_label_set_label (_tmp17_, _tmp18_);
			break;
		}
	}
	_g_object_unref0 (label_style_context);
}


static void fingerprint_credentials_class_init (FingerprintCredentialsClass * klass) {
	fingerprint_credentials_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (FingerprintCredentialsPrivate));
	G_OBJECT_CLASS (klass)->finalize = fingerprint_credentials_finalize;
}


static void fingerprint_credentials_credentials_interface_init (CredentialsIface * iface) {
	fingerprint_credentials_credentials_parent_iface = g_type_interface_peek_parent (iface);
	iface->show_message = (void (*)(Credentials*, LightDMMessageType, MessageText, const gchar*)) fingerprint_credentials_real_show_message;
}


static void fingerprint_credentials_instance_init (FingerprintCredentials * self) {
	self->priv = FINGERPRINT_CREDENTIALS_GET_PRIVATE (self);
}


static void fingerprint_credentials_finalize (GObject* obj) {
	FingerprintCredentials * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_FINGERPRINT_CREDENTIALS, FingerprintCredentials);
	_g_object_unref0 (self->priv->label);
	G_OBJECT_CLASS (fingerprint_credentials_parent_class)->finalize (obj);
}


GType fingerprint_credentials_get_type (void) {
	static volatile gsize fingerprint_credentials_type_id__volatile = 0;
	if (g_once_init_enter (&fingerprint_credentials_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FingerprintCredentialsClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fingerprint_credentials_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FingerprintCredentials), 0, (GInstanceInitFunc) fingerprint_credentials_instance_init, NULL };
		static const GInterfaceInfo credentials_info = { (GInterfaceInitFunc) fingerprint_credentials_credentials_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType fingerprint_credentials_type_id;
		fingerprint_credentials_type_id = g_type_register_static (gtk_grid_get_type (), "FingerprintCredentials", &g_define_type_info, 0);
		g_type_add_interface_static (fingerprint_credentials_type_id, TYPE_CREDENTIALS, &credentials_info);
		g_once_init_leave (&fingerprint_credentials_type_id__volatile, fingerprint_credentials_type_id);
	}
	return fingerprint_credentials_type_id__volatile;
}


