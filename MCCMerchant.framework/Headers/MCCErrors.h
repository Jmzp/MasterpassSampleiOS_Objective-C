/*
 *    MCSMerchantSDKErrors.h
 *    MCCMerchant
 *
 * 	  Copyright © 2015-2017, Mastercard International Incorporated and/or its
 *    affiliates. All rights reserved.
 *
 *    TO THE EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS", WITHOUT
 *    WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 *    WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *    NON INFRINGEMENT. TO THE EXTENT PERMITTED BY LAW, IN NO EVENT SHALL
 *    MASTERCARD OR ITS AFFILIATES BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 *    IN THE SOFTWARE.
 *
 */


#import <Foundation/Foundation.h>

/// The domain for errors originating from SDK initialization
extern NSString * _Nullable const MCCMerchantSDKInitializationErrorDomain;

/// The domain for errors originating from transaction processing
extern NSString * _Nullable const MCCMerchantSDKTransactionErrorDomain;

/// The domain for errors originating from Exception.
extern NSString * _Nullable const MCCMerchantErrorDomain;


/**
 * MCCMerchantErrorCode, this enum is for different error codes based on their classification
 */
typedef NS_ENUM(NSInteger, MCCMerchantErrorCode) {
    
    ///Required parameter is not passed
    MCCValidationMissingMandatoryParameterError      = 10000,
    
    ///The data type of the value is not matching with expected data type.
    MCCValidationInvalidTypeError                    = 10001,
    
    ///Empty, formatting etc...
    MCCValidationInvalidValueError                   = 10002,
    
    ///Internal operation(s) has timed out. Try again.
    MCCOperationTimeoutError                         = 10004,
    
    ///Internal problem. Please contact developer support
    MCCInternalError                                 = 10005,
    
    ///Network connectivity problem
    MCCNetworkError                                  = 10006,
    
    ///Network is present but error returned from server
    MCCCommunicationError                            = 10007,
    
    ///Any internal exception
    MCCExceptionError                                = 10008,
    
    ///Error code when transaction fail
    MCCTransactionError               = 10009,
    
    MCCOpenURLError                                  = 10010,
    
    MCCTransactionCancelled                          = 10011
};

