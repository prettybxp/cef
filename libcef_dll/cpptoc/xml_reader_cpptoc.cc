// Copyright (c) 2023 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//
// $hash=e4ec9a462bd52b87a605d8c2c677b278943e55f9$
//

#include "libcef_dll/cpptoc/xml_reader_cpptoc.h"
#include "libcef_dll/cpptoc/stream_reader_cpptoc.h"
#include "libcef_dll/shutdown_checker.h"

// GLOBAL FUNCTIONS - Body may be edited by hand.

CEF_EXPORT cef_xml_reader_t* cef_xml_reader_create(
    cef_stream_reader_t* stream,
    cef_xml_encoding_type_t encodingType,
    const cef_string_t* URI) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: stream; type: refptr_same
  DCHECK(stream);
  if (!stream)
    return NULL;
  // Verify param: URI; type: string_byref_const
  DCHECK(URI);
  if (!URI)
    return NULL;

  // Execute
  CefRefPtr<CefXmlReader> _retval = CefXmlReader::Create(
      CefStreamReaderCppToC::Unwrap(stream), encodingType, CefString(URI));

  // Return type: refptr_same
  return CefXmlReaderCppToC::Wrap(_retval);
}

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

int CEF_CALLBACK xml_reader_move_to_next_node(struct _cef_xml_reader_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefXmlReaderCppToC::Get(self)->MoveToNextNode();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK xml_reader_close(struct _cef_xml_reader_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefXmlReaderCppToC::Get(self)->Close();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK xml_reader_has_error(struct _cef_xml_reader_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefXmlReaderCppToC::Get(self)->HasError();

  // Return type: bool
  return _retval;
}

cef_string_userfree_t CEF_CALLBACK
xml_reader_get_error(struct _cef_xml_reader_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefXmlReaderCppToC::Get(self)->GetError();

  // Return type: string
  return _retval.DetachToUserFree();
}

cef_xml_node_type_t CEF_CALLBACK
xml_reader_get_type(struct _cef_xml_reader_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return XML_NODE_UNSUPPORTED;

  // Execute
  cef_xml_node_type_t _retval = CefXmlReaderCppToC::Get(self)->GetType();

  // Return type: simple
  return _retval;
}

int CEF_CALLBACK xml_reader_get_depth(struct _cef_xml_reader_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  int _retval = CefXmlReaderCppToC::Get(self)->GetDepth();

  // Return type: simple
  return _retval;
}

cef_string_userfree_t CEF_CALLBACK
xml_reader_get_local_name(struct _cef_xml_reader_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefXmlReaderCppToC::Get(self)->GetLocalName();

  // Return type: string
  return _retval.DetachToUserFree();
}

cef_string_userfree_t CEF_CALLBACK
xml_reader_get_prefix(struct _cef_xml_reader_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefXmlReaderCppToC::Get(self)->GetPrefix();

  // Return type: string
  return _retval.DetachToUserFree();
}

cef_string_userfree_t CEF_CALLBACK
xml_reader_get_qualified_name(struct _cef_xml_reader_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefXmlReaderCppToC::Get(self)->GetQualifiedName();

  // Return type: string
  return _retval.DetachToUserFree();
}

cef_string_userfree_t CEF_CALLBACK
xml_reader_get_namespace_uri(struct _cef_xml_reader_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefXmlReaderCppToC::Get(self)->GetNamespaceURI();

  // Return type: string
  return _retval.DetachToUserFree();
}

cef_string_userfree_t CEF_CALLBACK
xml_reader_get_base_uri(struct _cef_xml_reader_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefXmlReaderCppToC::Get(self)->GetBaseURI();

  // Return type: string
  return _retval.DetachToUserFree();
}

cef_string_userfree_t CEF_CALLBACK
xml_reader_get_xml_lang(struct _cef_xml_reader_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefXmlReaderCppToC::Get(self)->GetXmlLang();

  // Return type: string
  return _retval.DetachToUserFree();
}

int CEF_CALLBACK xml_reader_is_empty_element(struct _cef_xml_reader_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefXmlReaderCppToC::Get(self)->IsEmptyElement();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK xml_reader_has_value(struct _cef_xml_reader_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefXmlReaderCppToC::Get(self)->HasValue();

  // Return type: bool
  return _retval;
}

cef_string_userfree_t CEF_CALLBACK
xml_reader_get_value(struct _cef_xml_reader_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefXmlReaderCppToC::Get(self)->GetValue();

  // Return type: string
  return _retval.DetachToUserFree();
}

int CEF_CALLBACK xml_reader_has_attributes(struct _cef_xml_reader_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefXmlReaderCppToC::Get(self)->HasAttributes();

  // Return type: bool
  return _retval;
}

size_t CEF_CALLBACK
xml_reader_get_attribute_count(struct _cef_xml_reader_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  size_t _retval = CefXmlReaderCppToC::Get(self)->GetAttributeCount();

  // Return type: simple
  return _retval;
}

cef_string_userfree_t CEF_CALLBACK
xml_reader_get_attribute_byindex(struct _cef_xml_reader_t* self, int index) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;
  // Verify param: index; type: simple_byval
  DCHECK_GE(index, 0);
  if (index < 0)
    return NULL;

  // Execute
  CefString _retval = CefXmlReaderCppToC::Get(self)->GetAttribute(index);

  // Return type: string
  return _retval.DetachToUserFree();
}

cef_string_userfree_t CEF_CALLBACK
xml_reader_get_attribute_byqname(struct _cef_xml_reader_t* self,
                                 const cef_string_t* qualifiedName) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;
  // Verify param: qualifiedName; type: string_byref_const
  DCHECK(qualifiedName);
  if (!qualifiedName)
    return NULL;

  // Execute
  CefString _retval =
      CefXmlReaderCppToC::Get(self)->GetAttribute(CefString(qualifiedName));

  // Return type: string
  return _retval.DetachToUserFree();
}

cef_string_userfree_t CEF_CALLBACK
xml_reader_get_attribute_bylname(struct _cef_xml_reader_t* self,
                                 const cef_string_t* localName,
                                 const cef_string_t* namespaceURI) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;
  // Verify param: localName; type: string_byref_const
  DCHECK(localName);
  if (!localName)
    return NULL;
  // Verify param: namespaceURI; type: string_byref_const
  DCHECK(namespaceURI);
  if (!namespaceURI)
    return NULL;

  // Execute
  CefString _retval = CefXmlReaderCppToC::Get(self)->GetAttribute(
      CefString(localName), CefString(namespaceURI));

  // Return type: string
  return _retval.DetachToUserFree();
}

cef_string_userfree_t CEF_CALLBACK
xml_reader_get_inner_xml(struct _cef_xml_reader_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefXmlReaderCppToC::Get(self)->GetInnerXml();

  // Return type: string
  return _retval.DetachToUserFree();
}

cef_string_userfree_t CEF_CALLBACK
xml_reader_get_outer_xml(struct _cef_xml_reader_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefXmlReaderCppToC::Get(self)->GetOuterXml();

  // Return type: string
  return _retval.DetachToUserFree();
}

int CEF_CALLBACK xml_reader_get_line_number(struct _cef_xml_reader_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  int _retval = CefXmlReaderCppToC::Get(self)->GetLineNumber();

  // Return type: simple
  return _retval;
}

int CEF_CALLBACK
xml_reader_move_to_attribute_byindex(struct _cef_xml_reader_t* self,
                                     int index) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: index; type: simple_byval
  DCHECK_GE(index, 0);
  if (index < 0)
    return 0;

  // Execute
  bool _retval = CefXmlReaderCppToC::Get(self)->MoveToAttribute(index);

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK
xml_reader_move_to_attribute_byqname(struct _cef_xml_reader_t* self,
                                     const cef_string_t* qualifiedName) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: qualifiedName; type: string_byref_const
  DCHECK(qualifiedName);
  if (!qualifiedName)
    return 0;

  // Execute
  bool _retval =
      CefXmlReaderCppToC::Get(self)->MoveToAttribute(CefString(qualifiedName));

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK
xml_reader_move_to_attribute_bylname(struct _cef_xml_reader_t* self,
                                     const cef_string_t* localName,
                                     const cef_string_t* namespaceURI) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: localName; type: string_byref_const
  DCHECK(localName);
  if (!localName)
    return 0;
  // Verify param: namespaceURI; type: string_byref_const
  DCHECK(namespaceURI);
  if (!namespaceURI)
    return 0;

  // Execute
  bool _retval = CefXmlReaderCppToC::Get(self)->MoveToAttribute(
      CefString(localName), CefString(namespaceURI));

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK
xml_reader_move_to_first_attribute(struct _cef_xml_reader_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefXmlReaderCppToC::Get(self)->MoveToFirstAttribute();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK
xml_reader_move_to_next_attribute(struct _cef_xml_reader_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefXmlReaderCppToC::Get(self)->MoveToNextAttribute();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK
xml_reader_move_to_carrying_element(struct _cef_xml_reader_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefXmlReaderCppToC::Get(self)->MoveToCarryingElement();

  // Return type: bool
  return _retval;
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

CefXmlReaderCppToC::CefXmlReaderCppToC() {
  GetStruct()->move_to_next_node = xml_reader_move_to_next_node;
  GetStruct()->close = xml_reader_close;
  GetStruct()->has_error = xml_reader_has_error;
  GetStruct()->get_error = xml_reader_get_error;
  GetStruct()->get_type = xml_reader_get_type;
  GetStruct()->get_depth = xml_reader_get_depth;
  GetStruct()->get_local_name = xml_reader_get_local_name;
  GetStruct()->get_prefix = xml_reader_get_prefix;
  GetStruct()->get_qualified_name = xml_reader_get_qualified_name;
  GetStruct()->get_namespace_uri = xml_reader_get_namespace_uri;
  GetStruct()->get_base_uri = xml_reader_get_base_uri;
  GetStruct()->get_xml_lang = xml_reader_get_xml_lang;
  GetStruct()->is_empty_element = xml_reader_is_empty_element;
  GetStruct()->has_value = xml_reader_has_value;
  GetStruct()->get_value = xml_reader_get_value;
  GetStruct()->has_attributes = xml_reader_has_attributes;
  GetStruct()->get_attribute_count = xml_reader_get_attribute_count;
  GetStruct()->get_attribute_byindex = xml_reader_get_attribute_byindex;
  GetStruct()->get_attribute_byqname = xml_reader_get_attribute_byqname;
  GetStruct()->get_attribute_bylname = xml_reader_get_attribute_bylname;
  GetStruct()->get_inner_xml = xml_reader_get_inner_xml;
  GetStruct()->get_outer_xml = xml_reader_get_outer_xml;
  GetStruct()->get_line_number = xml_reader_get_line_number;
  GetStruct()->move_to_attribute_byindex = xml_reader_move_to_attribute_byindex;
  GetStruct()->move_to_attribute_byqname = xml_reader_move_to_attribute_byqname;
  GetStruct()->move_to_attribute_bylname = xml_reader_move_to_attribute_bylname;
  GetStruct()->move_to_first_attribute = xml_reader_move_to_first_attribute;
  GetStruct()->move_to_next_attribute = xml_reader_move_to_next_attribute;
  GetStruct()->move_to_carrying_element = xml_reader_move_to_carrying_element;
}

// DESTRUCTOR - Do not edit by hand.

CefXmlReaderCppToC::~CefXmlReaderCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
CefRefPtr<CefXmlReader>
CefCppToCRefCounted<CefXmlReaderCppToC, CefXmlReader, cef_xml_reader_t>::
    UnwrapDerived(CefWrapperType type, cef_xml_reader_t* s) {
  NOTREACHED() << "Unexpected class type: " << type;
  return nullptr;
}

template <>
CefWrapperType CefCppToCRefCounted<CefXmlReaderCppToC,
                                   CefXmlReader,
                                   cef_xml_reader_t>::kWrapperType =
    WT_XML_READER;
