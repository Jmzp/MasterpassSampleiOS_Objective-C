/*
 *    MCCCheckoutResponse.h
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

/**
 Represents the Resopnse details of checkout service. The developer will get object of this class in respones of checkout.
 */
@interface MCCCheckoutResponse : NSObject

///This property contains cart id from checkout service for merchant.
@property (nonatomic, strong) NSString* cartId;

///This property contains checkout resource url from checkout service for merchant.
@property (nonatomic, strong) NSString* checkoutResourceURL;

///This property contains transaction id from checkout service for merchant.
@property (nonatomic, strong) NSString* transactionId;

///This property contains checkoutType from checkout service for merchant.
@property (nonatomic, assign) MCCResponseType responseType;

///This property contains pairing transaction id from  checkout service for merchant.
@property (nonatomic, strong) NSString* pairingTransactionID;

///This property contains user id  from express checkout service for merchant.
@property (nonatomic, strong) NSString* pairingUserID;

///This property contains dictonary with response service for merchant.
@property (nonatomic, retain) NSDictionary* dictionary;

/**
 *  Initializes the response class with dictionary and responseType of response
 *
 *  @param dictionary of response
 *  @param MCCResponseType of responseType
 *
 *  @return An instance of the MCCCheckoutResponse class
 */
- (instancetype) initWithDictionary:(NSDictionary *)dictionary andResponseType:(MCCResponseType)responseType;

@end
