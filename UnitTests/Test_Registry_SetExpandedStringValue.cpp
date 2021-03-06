#include "stdafx.h"
#include "Test_Registry.h"
#include "TUtils.h"
#include "TConstants.h"

using namespace std;
using namespace WinReg;
using namespace TConst;

TEST_F(Test_Registry_SetExpandedStringValue, when_calling_setexpandedstringvalue_with_valid_parameters_values_expect_no_exception)
{
	try
	{
		Registry::SetExpandedStringValue(eHKey::eHKeyUsers, WS_TEST_SUBKEY, WS_EXPANDEDSTRING_VALUENAME, WS_ES_TESTVAL_1);
		wstring wsRegVal{ Registry::GetExpandedStringValue(eHKey::eHKeyUsers, WS_TEST_SUBKEY, WS_EXPANDEDSTRING_VALUENAME) };
		//wcout << L"[  VALUE   ] " << wsRegVal.c_str() << endl;
		ASSERT_EQ(wsRegVal, WS_ES_TESTVAL_1) << "[  FAILED  ] wsRegVal is not equal to WS_ES_TESTVAL_1";

		Registry::SetExpandedStringValue(eHKey::eHKeyUsers, WS_TEST_SUBKEY, WS_EXPANDEDSTRING_VALUENAME, WS_ES_TESTVAL_2);
		wsRegVal = Registry::GetExpandedStringValue(eHKey::eHKeyUsers, WS_TEST_SUBKEY, WS_EXPANDEDSTRING_VALUENAME);
		//wcout << L"[  VALUE   ] " << wsRegVal.c_str() << endl;
		ASSERT_EQ(wsRegVal, WS_ES_TESTVAL_2) << "[  FAILED  ] wsRegVal is not equal to WS_ES_TESTVAL_2";
	}
	catch (exception &ex)
	{
		ASSERT_TRUE(false) << "[EXCEPTION ] " << TUtils::ErrMsg(ex);
	}
	catch (...)
	{
		ASSERT_TRUE(false) << "[EXCEPTION ] Unknown exception";
	}
}

TEST_F(Test_Registry_SetExpandedStringValue, when_calling_setexpandedstringvalue_with_invalid_hkey_expect_exception)
{
	try
	{
		Registry::SetExpandedStringValue(eHKey::eHkeyNotDefined, WS_TEST_SUBKEY, WS_EXPANDEDSTRING_VALUENAME, WS_ES_TESTVAL_1);
		ASSERT_FALSE(true) << "[  FAILED  ] Expected an exception";
	}
	catch (exception &ex)
	{
		ASSERT_TRUE(TUtils::InString(TUtils::ErrMsg(ex), WS_INVALID_PARAM_VALUE)) << "[EXCEPTION ] " << TUtils::ErrMsg(ex);
	}
	catch (...)
	{
		ASSERT_TRUE(false) << "[EXCEPTION ] Unknown exception";
	}
}