// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "libcef/browser/permissions/permission_util.h"

#include "base/logging.h"

using content::PermissionType;

namespace permission_util {

// Copied from chrome/browser/permissions/permission_manager.cc.
ContentSettingsType PermissionTypeToContentSetting(PermissionType permission) {
  switch (permission) {
    case PermissionType::MIDI:
      return CONTENT_SETTINGS_TYPE_MIDI;
    case PermissionType::MIDI_SYSEX:
      return CONTENT_SETTINGS_TYPE_MIDI_SYSEX;
    case PermissionType::NOTIFICATIONS:
      return CONTENT_SETTINGS_TYPE_NOTIFICATIONS;
    case PermissionType::GEOLOCATION:
      return CONTENT_SETTINGS_TYPE_GEOLOCATION;
    case PermissionType::PROTECTED_MEDIA_IDENTIFIER:
#if defined(OS_ANDROID) || defined(OS_CHROMEOS)
      return CONTENT_SETTINGS_TYPE_PROTECTED_MEDIA_IDENTIFIER;
#else
      NOTIMPLEMENTED();
      break;
#endif
    case PermissionType::DURABLE_STORAGE:
      return CONTENT_SETTINGS_TYPE_DURABLE_STORAGE;
    case PermissionType::AUDIO_CAPTURE:
      return CONTENT_SETTINGS_TYPE_MEDIASTREAM_MIC;
    case PermissionType::VIDEO_CAPTURE:
      return CONTENT_SETTINGS_TYPE_MEDIASTREAM_CAMERA;
    case PermissionType::BACKGROUND_SYNC:
      return CONTENT_SETTINGS_TYPE_BACKGROUND_SYNC;
    case PermissionType::FLASH:
      return CONTENT_SETTINGS_TYPE_PLUGINS;
    case PermissionType::SENSORS:
      return CONTENT_SETTINGS_TYPE_SENSORS;
    case PermissionType::ACCESSIBILITY_EVENTS:
      return CONTENT_SETTINGS_TYPE_ACCESSIBILITY_EVENTS;
    case PermissionType::CLIPBOARD_READ:
      return CONTENT_SETTINGS_TYPE_CLIPBOARD_READ;
    case PermissionType::CLIPBOARD_WRITE:
      return CONTENT_SETTINGS_TYPE_CLIPBOARD_WRITE;
    case PermissionType::NUM:
      // This will hit the NOTREACHED below.
      break;
  }

  NOTREACHED() << "Unknown content setting for permission "
               << static_cast<int>(permission);
  return CONTENT_SETTINGS_TYPE_DEFAULT;
}

}  // namespace permission_util