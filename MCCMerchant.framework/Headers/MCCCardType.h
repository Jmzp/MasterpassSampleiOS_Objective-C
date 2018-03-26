/*
 *    MCCCardType.h
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
#import "MCCMerchantConstants.h"

@interface MCCCardType : NSObject

@property(nonatomic, assign, readonly) MCCCard cardType;
@property(nonatomic, strong, readonly,nonnull) NSString *cardIdentifier;

// Unavailable
- (instancetype _Nullable )init NS_UNAVAILABLE;

/**
 *  Designated initilizer to instanstiate the card type object
 *
 *  @param cardType The identifier for the card type. The default will be MCCCardMASTER.
 */
- (instancetype _Nullable)initWithType:(MCCCard)cardType NS_DESIGNATED_INITIALIZER;

@end
