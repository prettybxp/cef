// Copyright (c) 2023 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//
// $hash=333350f8141cc925d16df2edc8c21a720a1008f0$
//

#ifndef CEF_INCLUDE_CAPI_CEF_MEDIA_ROUTER_CAPI_H_
#define CEF_INCLUDE_CAPI_CEF_MEDIA_ROUTER_CAPI_H_
#pragma once

#include "include/capi/cef_base_capi.h"
#include "include/capi/cef_callback_capi.h"
#include "include/capi/cef_registration_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

struct _cef_media_observer_t;
struct _cef_media_route_create_callback_t;
struct _cef_media_route_t;
struct _cef_media_sink_device_info_callback_t;
struct _cef_media_sink_t;
struct _cef_media_source_t;

///
/// Supports discovery of and communication with media devices on the local
/// network via the Cast and DIAL protocols. The functions of this structure may
/// be called on any browser process thread unless otherwise indicated.
///
typedef struct _cef_media_router_t {
  ///
  /// Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  /// Add an observer for MediaRouter events. The observer will remain
  /// registered until the returned Registration object is destroyed.
  ///
  struct _cef_registration_t*(CEF_CALLBACK* add_observer)(
      struct _cef_media_router_t* self,
      struct _cef_media_observer_t* observer);

  ///
  /// Returns a MediaSource object for the specified media source URN. Supported
  /// URN schemes include "cast:" and "dial:", and will be already known by the
  /// client application (e.g. "cast:<appId>?clientId=<clientId>").
  ///
  struct _cef_media_source_t*(CEF_CALLBACK* get_source)(
      struct _cef_media_router_t* self,
      const cef_string_t* urn);

  ///
  /// Trigger an asynchronous call to cef_media_observer_t::OnSinks on all
  /// registered observers.
  ///
  void(CEF_CALLBACK* notify_current_sinks)(struct _cef_media_router_t* self);

  ///
  /// Create a new route between |source| and |sink|. Source and sink must be
  /// valid, compatible (as reported by cef_media_sink_t::IsCompatibleWith), and
  /// a route between them must not already exist. |callback| will be executed
  /// on success or failure. If route creation succeeds it will also trigger an
  /// asynchronous call to cef_media_observer_t::OnRoutes on all registered
  /// observers.
  ///
  void(CEF_CALLBACK* create_route)(
      struct _cef_media_router_t* self,
      struct _cef_media_source_t* source,
      struct _cef_media_sink_t* sink,
      struct _cef_media_route_create_callback_t* callback);

  ///
  /// Trigger an asynchronous call to cef_media_observer_t::OnRoutes on all
  /// registered observers.
  ///
  void(CEF_CALLBACK* notify_current_routes)(struct _cef_media_router_t* self);
} cef_media_router_t;

///
/// Returns the MediaRouter object associated with the global request context.
/// If |callback| is non-NULL it will be executed asnychronously on the UI
/// thread after the manager's storage has been initialized. Equivalent to
/// calling cef_request_context_t::cef_request_context_get_global_context()->get
/// _media_router().
///
CEF_EXPORT cef_media_router_t* cef_media_router_get_global(
    struct _cef_completion_callback_t* callback);

///
/// Implemented by the client to observe MediaRouter events and registered via
/// cef_media_router_t::AddObserver. The functions of this structure will be
/// called on the browser process UI thread.
///
typedef struct _cef_media_observer_t {
  ///
  /// Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  /// The list of available media sinks has changed or
  /// cef_media_router_t::NotifyCurrentSinks was called.
  ///
  void(CEF_CALLBACK* on_sinks)(struct _cef_media_observer_t* self,
                               size_t sinksCount,
                               struct _cef_media_sink_t* const* sinks);

  ///
  /// The list of available media routes has changed or
  /// cef_media_router_t::NotifyCurrentRoutes was called.
  ///
  void(CEF_CALLBACK* on_routes)(struct _cef_media_observer_t* self,
                                size_t routesCount,
                                struct _cef_media_route_t* const* routes);

  ///
  /// The connection state of |route| has changed.
  ///
  void(CEF_CALLBACK* on_route_state_changed)(
      struct _cef_media_observer_t* self,
      struct _cef_media_route_t* route,
      cef_media_route_connection_state_t state);

  ///
  /// A message was recieved over |route|. |message| is only valid for the scope
  /// of this callback and should be copied if necessary.
  ///
  void(CEF_CALLBACK* on_route_message_received)(
      struct _cef_media_observer_t* self,
      struct _cef_media_route_t* route,
      const void* message,
      size_t message_size);
} cef_media_observer_t;

///
/// Represents the route between a media source and sink. Instances of this
/// object are created via cef_media_router_t::CreateRoute and retrieved via
/// cef_media_observer_t::OnRoutes. Contains the status and metadata of a
/// routing operation. The functions of this structure may be called on any
/// browser process thread unless otherwise indicated.
///
typedef struct _cef_media_route_t {
  ///
  /// Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  /// Returns the ID for this route.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_id)(struct _cef_media_route_t* self);

  ///
  /// Returns the source associated with this route.
  ///
  struct _cef_media_source_t*(CEF_CALLBACK* get_source)(
      struct _cef_media_route_t* self);

  ///
  /// Returns the sink associated with this route.
  ///
  struct _cef_media_sink_t*(CEF_CALLBACK* get_sink)(
      struct _cef_media_route_t* self);

  ///
  /// Send a message over this route. |message| will be copied if necessary.
  ///
  void(CEF_CALLBACK* send_route_message)(struct _cef_media_route_t* self,
                                         const void* message,
                                         size_t message_size);

  ///
  /// Terminate this route. Will result in an asynchronous call to
  /// cef_media_observer_t::OnRoutes on all registered observers.
  ///
  void(CEF_CALLBACK* terminate)(struct _cef_media_route_t* self);
} cef_media_route_t;

///
/// Callback structure for cef_media_router_t::CreateRoute. The functions of
/// this structure will be called on the browser process UI thread.
///
typedef struct _cef_media_route_create_callback_t {
  ///
  /// Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  /// Method that will be executed when the route creation has finished.
  /// |result| will be CEF_MRCR_OK if the route creation succeeded. |error| will
  /// be a description of the error if the route creation failed. |route| is the
  /// resulting route, or NULL if the route creation failed.
  ///
  void(CEF_CALLBACK* on_media_route_create_finished)(
      struct _cef_media_route_create_callback_t* self,
      cef_media_route_create_result_t result,
      const cef_string_t* error,
      struct _cef_media_route_t* route);
} cef_media_route_create_callback_t;

///
/// Represents a sink to which media can be routed. Instances of this object are
/// retrieved via cef_media_observer_t::OnSinks. The functions of this structure
/// may be called on any browser process thread unless otherwise indicated.
///
typedef struct _cef_media_sink_t {
  ///
  /// Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  /// Returns the ID for this sink.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_id)(struct _cef_media_sink_t* self);

  ///
  /// Returns the name of this sink.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_name)(struct _cef_media_sink_t* self);

  ///
  /// Returns the description of this sink.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_description)(
      struct _cef_media_sink_t* self);

  ///
  /// Returns the icon type for this sink.
  ///
  cef_media_sink_icon_type_t(CEF_CALLBACK* get_icon_type)(
      struct _cef_media_sink_t* self);

  ///
  /// Asynchronously retrieves device info.
  ///
  void(CEF_CALLBACK* get_device_info)(
      struct _cef_media_sink_t* self,
      struct _cef_media_sink_device_info_callback_t* callback);

  ///
  /// Returns true (1) if this sink accepts content via Cast.
  ///
  int(CEF_CALLBACK* is_cast_sink)(struct _cef_media_sink_t* self);

  ///
  /// Returns true (1) if this sink accepts content via DIAL.
  ///
  int(CEF_CALLBACK* is_dial_sink)(struct _cef_media_sink_t* self);

  ///
  /// Returns true (1) if this sink is compatible with |source|.
  ///
  int(CEF_CALLBACK* is_compatible_with)(struct _cef_media_sink_t* self,
                                        struct _cef_media_source_t* source);
} cef_media_sink_t;

///
/// Callback structure for cef_media_sink_t::GetDeviceInfo. The functions of
/// this structure will be called on the browser process UI thread.
///
typedef struct _cef_media_sink_device_info_callback_t {
  ///
  /// Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  /// Method that will be executed asyncronously once device information has
  /// been retrieved.
  ///
  void(CEF_CALLBACK* on_media_sink_device_info)(
      struct _cef_media_sink_device_info_callback_t* self,
      const struct _cef_media_sink_device_info_t* device_info);
} cef_media_sink_device_info_callback_t;

///
/// Represents a source from which media can be routed. Instances of this object
/// are retrieved via cef_media_router_t::GetSource. The functions of this
/// structure may be called on any browser process thread unless otherwise
/// indicated.
///
typedef struct _cef_media_source_t {
  ///
  /// Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  /// Returns the ID (media source URN or URL) for this source.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_id)(struct _cef_media_source_t* self);

  ///
  /// Returns true (1) if this source outputs its content via Cast.
  ///
  int(CEF_CALLBACK* is_cast_source)(struct _cef_media_source_t* self);

  ///
  /// Returns true (1) if this source outputs its content via DIAL.
  ///
  int(CEF_CALLBACK* is_dial_source)(struct _cef_media_source_t* self);
} cef_media_source_t;

#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_CEF_MEDIA_ROUTER_CAPI_H_
