/* soapSLEWebServiceSoapProxy.cpp
   Generated by gSOAP 2.8.4 from webpaysoap.h

Copyright(C) 2000-2011, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
1) GPL or 2) Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#include "soapSLEWebServiceSoapProxy.h"

SLEWebServiceSoapProxy::SLEWebServiceSoapProxy()
{	SLEWebServiceSoapProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

SLEWebServiceSoapProxy::SLEWebServiceSoapProxy(const struct soap &_soap) : soap(_soap)
{ }

SLEWebServiceSoapProxy::SLEWebServiceSoapProxy(const char *url)
{	SLEWebServiceSoapProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
	soap_endpoint = url;
}

SLEWebServiceSoapProxy::SLEWebServiceSoapProxy(soap_mode iomode)
{	SLEWebServiceSoapProxy_init(iomode, iomode);
}

SLEWebServiceSoapProxy::SLEWebServiceSoapProxy(const char *url, soap_mode iomode)
{	SLEWebServiceSoapProxy_init(iomode, iomode);
	soap_endpoint = url;
}

SLEWebServiceSoapProxy::SLEWebServiceSoapProxy(soap_mode imode, soap_mode omode)
{	SLEWebServiceSoapProxy_init(imode, omode);
}

SLEWebServiceSoapProxy::~SLEWebServiceSoapProxy()
{ }

void SLEWebServiceSoapProxy::SLEWebServiceSoapProxy_init(soap_mode imode, soap_mode omode)
{	soap_imode(this, imode);
	soap_omode(this, omode);
	soap_endpoint = NULL;
	static const struct Namespace namespaces[] =
{
	{"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
	{"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"ns2", "http://tempuri.org/SLEWebServiceSoap", NULL, NULL},
	{"ns1", "http://tempuri.org/", NULL, NULL},
	{"ns3", "http://tempuri.org/SLEWebServiceSoap12", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};
	soap_set_namespaces(this, namespaces);
}

void SLEWebServiceSoapProxy::destroy()
{	soap_destroy(this);
	soap_end(this);
}

void SLEWebServiceSoapProxy::soap_noheader()
{	this->header = NULL;
}

const SOAP_ENV__Header *SLEWebServiceSoapProxy::soap_header()
{	return this->header;
}

const SOAP_ENV__Fault *SLEWebServiceSoapProxy::soap_fault()
{	return this->fault;
}

const char *SLEWebServiceSoapProxy::soap_fault_string()
{	return *soap_faultstring(this);
}

const char *SLEWebServiceSoapProxy::soap_fault_detail()
{	return *soap_faultdetail(this);
}

int SLEWebServiceSoapProxy::soap_close_socket()
{	return soap_closesock(this);
}

int SLEWebServiceSoapProxy::soap_force_close_socket()
{	return soap_force_closesock(this);
}

void SLEWebServiceSoapProxy::soap_print_fault(FILE *fd)
{	::soap_print_fault(this, fd);
}

#ifndef WITH_LEAN
void SLEWebServiceSoapProxy::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this, os);
}

char *SLEWebServiceSoapProxy::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this, buf, len);
}
#endif

int SLEWebServiceSoapProxy::S1_USCORE001(const char *endpoint, const char *soap_action, _ns1__S1_USCORE001 *ns1__S1_USCORE001, _ns1__S1_USCORE001Response *ns1__S1_USCORE001Response)
{	struct soap *soap = this;
	struct __ns2__S1_USCORE001 soap_tmp___ns2__S1_USCORE001;
	if (endpoint)
		soap_endpoint = endpoint;
	if (!soap_endpoint)
		soap_endpoint = "http://ygp.gzmtr.cn:9090/SnapQRCPay/SLEWebService.asmx";
	if (!soap_action)
		soap_action = "http://tempuri.org/S1_001";
	soap->encodingStyle = NULL;
	soap_tmp___ns2__S1_USCORE001.ns1__S1_USCORE001 = ns1__S1_USCORE001;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns2__S1_USCORE001(soap, &soap_tmp___ns2__S1_USCORE001);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns2__S1_USCORE001(soap, &soap_tmp___ns2__S1_USCORE001, "-ns2:S1_001", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns2__S1_USCORE001(soap, &soap_tmp___ns2__S1_USCORE001, "-ns2:S1_001", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__S1_USCORE001Response)
		return soap_closesock(soap);
	ns1__S1_USCORE001Response->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__S1_USCORE001Response->soap_get(soap, "ns1:S1_001Response", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int SLEWebServiceSoapProxy::S1_USCORE004(const char *endpoint, const char *soap_action, _ns1__S1_USCORE004 *ns1__S1_USCORE004, _ns1__S1_USCORE004Response *ns1__S1_USCORE004Response)
{	struct soap *soap = this;
	struct __ns2__S1_USCORE004 soap_tmp___ns2__S1_USCORE004;
	if (endpoint)
		soap_endpoint = endpoint;
	if (!soap_endpoint)
		soap_endpoint = "http://ygp.gzmtr.cn:9090/SnapQRCPay/SLEWebService.asmx";
	if (!soap_action)
		soap_action = "http://tempuri.org/S1_004";
	soap->encodingStyle = NULL;
	soap_tmp___ns2__S1_USCORE004.ns1__S1_USCORE004 = ns1__S1_USCORE004;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns2__S1_USCORE004(soap, &soap_tmp___ns2__S1_USCORE004);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns2__S1_USCORE004(soap, &soap_tmp___ns2__S1_USCORE004, "-ns2:S1_004", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns2__S1_USCORE004(soap, &soap_tmp___ns2__S1_USCORE004, "-ns2:S1_004", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__S1_USCORE004Response)
		return soap_closesock(soap);
	ns1__S1_USCORE004Response->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__S1_USCORE004Response->soap_get(soap, "ns1:S1_004Response", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int SLEWebServiceSoapProxy::S1_USCORE005(const char *endpoint, const char *soap_action, _ns1__S1_USCORE005 *ns1__S1_USCORE005, _ns1__S1_USCORE005Response *ns1__S1_USCORE005Response)
{	struct soap *soap = this;
	struct __ns2__S1_USCORE005 soap_tmp___ns2__S1_USCORE005;
	if (endpoint)
		soap_endpoint = endpoint;
	if (!soap_endpoint)
		soap_endpoint = "http://ygp.gzmtr.cn:9090/SnapQRCPay/SLEWebService.asmx";
	if (!soap_action)
		soap_action = "http://tempuri.org/S1_005";
	soap->encodingStyle = NULL;
	soap_tmp___ns2__S1_USCORE005.ns1__S1_USCORE005 = ns1__S1_USCORE005;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns2__S1_USCORE005(soap, &soap_tmp___ns2__S1_USCORE005);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns2__S1_USCORE005(soap, &soap_tmp___ns2__S1_USCORE005, "-ns2:S1_005", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns2__S1_USCORE005(soap, &soap_tmp___ns2__S1_USCORE005, "-ns2:S1_005", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__S1_USCORE005Response)
		return soap_closesock(soap);
	ns1__S1_USCORE005Response->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__S1_USCORE005Response->soap_get(soap, "ns1:S1_005Response", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int SLEWebServiceSoapProxy::S1_USCORE009(const char *endpoint, const char *soap_action, _ns1__S1_USCORE009 *ns1__S1_USCORE009, _ns1__S1_USCORE009Response *ns1__S1_USCORE009Response)
{	struct soap *soap = this;
	struct __ns2__S1_USCORE009 soap_tmp___ns2__S1_USCORE009;
	if (endpoint)
		soap_endpoint = endpoint;
	if (!soap_endpoint)
		soap_endpoint = "http://ygp.gzmtr.cn:9090/SnapQRCPay/SLEWebService.asmx";
	if (!soap_action)
		soap_action = "http://tempuri.org/S1_009";
	soap->encodingStyle = NULL;
	soap_tmp___ns2__S1_USCORE009.ns1__S1_USCORE009 = ns1__S1_USCORE009;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns2__S1_USCORE009(soap, &soap_tmp___ns2__S1_USCORE009);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns2__S1_USCORE009(soap, &soap_tmp___ns2__S1_USCORE009, "-ns2:S1_009", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns2__S1_USCORE009(soap, &soap_tmp___ns2__S1_USCORE009, "-ns2:S1_009", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__S1_USCORE009Response)
		return soap_closesock(soap);
	ns1__S1_USCORE009Response->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__S1_USCORE009Response->soap_get(soap, "ns1:S1_009Response", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int SLEWebServiceSoapProxy::S1_USCORE018(const char *endpoint, const char *soap_action, _ns1__S1_USCORE018 *ns1__S1_USCORE018, _ns1__S1_USCORE018Response *ns1__S1_USCORE018Response)
{	struct soap *soap = this;
	struct __ns2__S1_USCORE018 soap_tmp___ns2__S1_USCORE018;
	if (endpoint)
		soap_endpoint = endpoint;
	if (!soap_endpoint)
		soap_endpoint = "http://ygp.gzmtr.cn:9090/SnapQRCPay/SLEWebService.asmx";
	if (!soap_action)
		soap_action = "http://tempuri.org/S1_018";
	soap->encodingStyle = NULL;
	soap_tmp___ns2__S1_USCORE018.ns1__S1_USCORE018 = ns1__S1_USCORE018;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns2__S1_USCORE018(soap, &soap_tmp___ns2__S1_USCORE018);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns2__S1_USCORE018(soap, &soap_tmp___ns2__S1_USCORE018, "-ns2:S1_018", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns2__S1_USCORE018(soap, &soap_tmp___ns2__S1_USCORE018, "-ns2:S1_018", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__S1_USCORE018Response)
		return soap_closesock(soap);
	ns1__S1_USCORE018Response->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__S1_USCORE018Response->soap_get(soap, "ns1:S1_018Response", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int SLEWebServiceSoapProxy::S1_USCORE019(const char *endpoint, const char *soap_action, _ns1__S1_USCORE019 *ns1__S1_USCORE019, _ns1__S1_USCORE019Response *ns1__S1_USCORE019Response)
{	struct soap *soap = this;
	struct __ns2__S1_USCORE019 soap_tmp___ns2__S1_USCORE019;
	if (endpoint)
		soap_endpoint = endpoint;
	if (!soap_endpoint)
		soap_endpoint = "http://ygp.gzmtr.cn:9090/SnapQRCPay/SLEWebService.asmx";
	if (!soap_action)
		soap_action = "http://tempuri.org/S1_019";
	soap->encodingStyle = NULL;
	soap_tmp___ns2__S1_USCORE019.ns1__S1_USCORE019 = ns1__S1_USCORE019;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns2__S1_USCORE019(soap, &soap_tmp___ns2__S1_USCORE019);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns2__S1_USCORE019(soap, &soap_tmp___ns2__S1_USCORE019, "-ns2:S1_019", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns2__S1_USCORE019(soap, &soap_tmp___ns2__S1_USCORE019, "-ns2:S1_019", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__S1_USCORE019Response)
		return soap_closesock(soap);
	ns1__S1_USCORE019Response->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__S1_USCORE019Response->soap_get(soap, "ns1:S1_019Response", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int SLEWebServiceSoapProxy::S1_USCORE020(const char *endpoint, const char *soap_action, _ns1__S1_USCORE020 *ns1__S1_USCORE020, _ns1__S1_USCORE020Response *ns1__S1_USCORE020Response)
{	struct soap *soap = this;
	struct __ns2__S1_USCORE020 soap_tmp___ns2__S1_USCORE020;
	if (endpoint)
		soap_endpoint = endpoint;
	if (!soap_endpoint)
		soap_endpoint = "http://ygp.gzmtr.cn:9090/SnapQRCPay/SLEWebService.asmx";
	if (!soap_action)
		soap_action = "http://tempuri.org/S1_020";
	soap->encodingStyle = NULL;
	soap_tmp___ns2__S1_USCORE020.ns1__S1_USCORE020 = ns1__S1_USCORE020;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns2__S1_USCORE020(soap, &soap_tmp___ns2__S1_USCORE020);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns2__S1_USCORE020(soap, &soap_tmp___ns2__S1_USCORE020, "-ns2:S1_020", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns2__S1_USCORE020(soap, &soap_tmp___ns2__S1_USCORE020, "-ns2:S1_020", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__S1_USCORE020Response)
		return soap_closesock(soap);
	ns1__S1_USCORE020Response->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__S1_USCORE020Response->soap_get(soap, "ns1:S1_020Response", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}
/* End of client proxy code */
